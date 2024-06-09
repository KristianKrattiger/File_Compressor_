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
#include "huffman.h"

#include <fstream>
#include <iostream>
#include <map>
#include <bitset>

using namespace std;
namespace compressor {
    // Map to store character frequencies
    map<char, unsigned int> frequency_map;

    // Map to store Huffman codes for characters
    map<char, string> HuffmanCode;

    // MinHeap to build the Huffman tree
    MinHeap theMinHeap;

    // Function to build the Huffman Tree later used in compress and decompress
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

    // Function to read the file and generate the frequency map
    string readFile(const fs::path& filePath) {
    // First, check if the file exists before trying to open it
    if (!fs::exists(filePath)) {
        std::cerr << "File does not exist: " << filePath << std::endl;
        return "";
    }

    std::ifstream inFile(filePath, std::ios::binary); // Open in binary mode to preserve all data
    if (!inFile) {
        std::cerr << "Cannot open file: " << filePath << std::endl;
        return "";
    }

    frequency_map.clear(); // Clear previous data

    char tempChar;
    while (inFile.get(tempChar)) {
        frequency_map[tempChar]++;
        std::cout << tempChar;
    }

    // Print frequency table for debugging
    for (const auto& pair : frequency_map) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    inFile.close();
    return "File successfully read.\n";
}

    // Compress a file using Huffman coding
    void compress(const fs::path& inputFileName, const fs::path& outputFileName) {
        std::cout << "\nBuilding the Huffman tree...\n";
        HuffmanNode* root = buildHuffmanTree(frequency_map, theMinHeap);
        std::cout << "\nHuffman tree built.\n";
        root->printTree(root);

        std::cout << "\nEncoding the Huffman tree...\n";
        root->encode("", HuffmanCode);
        std::cout << "\nHuffman tree encoded.\n";

        std::ofstream outFile(outputFileName, std::ios::binary); // Open in binary mode to preserve all data
        if (!outFile) {
            std::cerr << "Cannot create file: " << outputFileName << std::endl;
            return;
        }

        std::ifstream inFile(inputFileName, std::ios::binary);
        char tempChar;
        std::string encodedContent;
        while (inFile.get(tempChar)) {
            encodedContent += HuffmanCode[tempChar];
        }

        while (encodedContent.size() % 8 != 0) {
            encodedContent += '0'; // Pad with zeros to make a full byte
        }

        for (size_t i = 0; i < encodedContent.size(); i += 8) {
            std::bitset<8> byte(encodedContent.substr(i, 8));
            outFile.put(static_cast<unsigned char>(byte.to_ulong()));
        }

        inFile.close();
        outFile.close();
    }

    // Decompress a file using Huffman coding
    void decompress(const fs::path& inputFileName, const fs::path& outputFileName) {
        std::ifstream infile(inputFileName, std::ios::binary);
        std::ofstream outfile(outputFileName, std::ios::binary);

        if (!infile) {
            std::cerr << "Cannot open file: " << inputFileName << std::endl;
            return;
        }

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

        HuffmanNode* root = buildHuffmanTree(frequency_map, theMinHeap);
        HuffmanNode* huffmanPtr = root;
        root->decode(huffmanPtr, infile, outfile);

        infile.close();
        outfile.close();
    }
}  // namespace compressor