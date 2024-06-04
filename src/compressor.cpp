/**
 * @file compressor.cpp
 * @brief Implementation of the compressor namespace and the HuffmanNode class.
 * 
 * This file contains the implementation of the compressor namespace, which provides functions for file compression
 * using Huffman coding. It also contains the HuffmanNode class, which represents a node in a Huffman tree.
 * The compressor namespace includes functions to read a file, compress it using Huffman coding, and decompress
 * a previously compressed file.
 * 
 * The compressor namespace uses a MinHeap to build the Huffman tree and stores the character frequencies in a map.
 * It also provides functions to encode and decode the Huffman tree.
 * 
 * The main functions in this file are:
 * - `readFile`: Reads the contents of a file and calculates character frequencies.
 * - `compress`: Compresses a file using Huffman coding.
 * - `decompress`: Decompresses a file using Huffman coding.
 * 
 * The HuffmanNode class represents a node in the Huffman tree and provides functions to print the tree, encode the tree,
 * and decode the tree.
 * 
 * The MinHeap class is used to build the Huffman tree by maintaining a min-heap of nodes.
 * It provides functions to insert nodes, extract the minimum node, and get the size of the heap.
 * 
 * The `frequency_map` and `HuffmanCode` maps are used to store character frequencies and Huffman codes respectively.
 * 
 * @auth
 */
#include "compressor.h"
#include <fstream>
#include <iostream>
#include <map>
#include <bitset> // Add this include for bitset

using namespace std;

namespace compressor {
    // Map to store character frequencies
    map<char, unsigned int> frequency_map;

    // Map to store Huffman codes for characters
    map<char, string> HuffmanCode;

    // MinHeap to build the Huffman tree
    MinHeap theMinHeap;

    // Build the Huffman tree.
    HuffmanNode* buildHuffmanTree(map<char, unsigned>& frequency_map, MinHeap& minHeap) {
        for (const auto& pair : frequency_map) {
            minHeap.insert(new HuffmanNode(pair.first, pair.second));
        }

        while (minHeap.size() > 1) {
            HuffmanNode* left = minHeap.extractMin();
            HuffmanNode* right = minHeap.extractMin();
            HuffmanNode* internalNode = new HuffmanNode(left, right);
            minHeap.insert(internalNode);
        }

        return minHeap.extractMin();  // Caller must manage the returned root
    }

    // Read the contents of a file and calculate character frequencies.
    string readFile(const string& filePath) {
        ifstream inFile(filePath, ios::binary); // Open in binary mode to preserve all data
        if (!inFile) {
            cerr << "Cannot open file: " << filePath << endl;
            return "";
        }

        frequency_map.clear(); // Clear previous data

        char tempChar;
        while (inFile.get(tempChar)) {
            frequency_map[tempChar]++;
        }

        // Print frequency table for debugging
        for (const auto& pair : frequency_map) {
            cout << pair.first << " " << pair.second << endl;
        }

        inFile.close();
        return "File successfully read.\n";
    }

    // Compress a file using Huffman coding.
    void compress(const string& inputFileName, const string& outputFileName) {
        // Build the Huffman tree  
        cout << "\nBuilding the Huffman tree...\n";
        HuffmanNode* root = buildHuffmanTree(frequency_map, theMinHeap);
        cout << "\nHuffman tree built.\n";
        root->printTree(root);

        // Encode the Huffman tree
        cout << "\nEncoding the Huffman tree...\n";
        root->encode("", HuffmanCode);
        cout << "\nHuffman tree encoded.\n";

        // Write the encoded data to the output file
        ofstream outFile(outputFileName, ios::binary); // Open in binary mode to preserve all data
        if (!outFile) {
            cerr << "Cannot create file: " << outputFileName << endl;
            return;
        }

        // Write the frequency table as metadata
        size_t size = frequency_map.size();
        outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));
        for (const auto& pair : frequency_map) {
            outFile.put(pair.first);
            outFile.write(reinterpret_cast<const char*>(&pair.second), sizeof(pair.second));
        }

        // Read the input file and write the encoded content
        ifstream inFile(inputFileName, ios::binary);
        char tempChar;
        string encodedContent;
        while (inFile.get(tempChar)) {
            encodedContent += HuffmanCode[tempChar];
        }

        // Convert the encoded string to binary format
        while (encodedContent.size() % 8 != 0) {
            encodedContent += '0'; // Pad with zeros to make a full byte
        }

        for (size_t i = 0; i < encodedContent.size(); i += 8) {
            bitset<8> byte(encodedContent.substr(i, 8));
            outFile.put(static_cast<unsigned char>(byte.to_ulong()));
        }

        inFile.close();
        outFile.close();
    }

    // Decompress a file using Huffman coding.
    void decompress(const string& inputFileName, const string& outputFileName) {
        ifstream infile(inputFileName, ios::binary);
        ofstream outfile(outputFileName, ios::binary);

        if (!infile) {
            cerr << "Cannot open file: " << inputFileName << endl;
            return;
        }

        // Rebuild the frequency table from the metadata
        size_t frequencyTableSize;
        infile.read(reinterpret_cast<char*>(&frequencyTableSize), sizeof(frequencyTableSize));
        frequency_map.clear();
        for (size_t i = 0; i < frequencyTableSize; ++i) {
            char ch;
            unsigned int freq;
            infile.get(ch);
            infile.read(reinterpret_cast<char*>(&freq), sizeof(freq));
            frequency_map[ch] = freq;
        }

        // Build the Huffman tree
        HuffmanNode* root = buildHuffmanTree(frequency_map, theMinHeap);

        HuffmanNode* huffmanPtr = root; // Temporary pointer to traverse the tree
        root->decode(huffmanPtr, infile, outfile);

        infile.close();
        outfile.close();
    }
}  // namespace compressor