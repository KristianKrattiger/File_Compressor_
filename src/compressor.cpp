#include "compressor.h"
#include "huffman.h"
#include <fstream>
#include <iostream>
#include <map>
#include <bitset>

using namespace std;

namespace compressor {
    map<char, unsigned int> frequency_map; // Map to store the frequency of each character in the file
    map<char, string> HuffmanCode;         // Map to store the Huffman code for each character
    MinHeap theMinHeap;                    // MinHeap to manage the Huffman nodes

    // Builds the Huffman tree from the frequency map using the MinHeap
    HuffmanNode* buildHuffmanTree(map<char, unsigned>& frequency_map, MinHeap& minHeap) {
        for (const auto& pair : frequency_map) {
            minHeap.insert(new HuffmanNode(pair.first, pair.second)); // Insert each character as a node in the MinHeap
        }

        // Combine nodes until only one remains in the MinHeap
        while (minHeap.size() > 1) {
            HuffmanNode* left = minHeap.extractMin();    // Extract the node with the smallest frequency
            HuffmanNode* right = minHeap.extractMin();   // Extract the next smallest frequency node
            HuffmanNode* internalNode = new HuffmanNode(left, right); // Create a new internal node
            minHeap.insert(internalNode);                // Insert the new internal node back into the MinHeap
        }

        return minHeap.extractMin(); // The remaining node is the root of the Huffman tree
    }

    // Compresses the input file using Huffman coding and writes the result to the output file
    void compress(const std::string& inputFileName, const std::string& outputFileName) {
        cout << "\nBuilding the Huffman tree...\n";
        HuffmanNode* root = buildHuffmanTree(frequency_map, theMinHeap); // Build the Huffman tree from the frequency map
        cout << "\nHuffman tree built.\n";
        root->printTree(root); // Optional: Print the Huffman tree for debugging

        cout << "\nEncoding the Huffman tree...\n";
        root->encode("", HuffmanCode); // Generate Huffman codes for each character
        cout << "\nHuffman tree encoded.\n";

        ofstream outFile(outputFileName, ios::binary);
        if (!outFile) {
            cerr << "Cannot create file: " << outputFileName << endl;
            return;
        }

        ifstream inFile(inputFileName, ios::binary);
        char tempChar;
        string encodedContent;
        while (inFile.get(tempChar)) {
            encodedContent += HuffmanCode[tempChar]; // Replace each character with its Huffman code
        }

        // Ensure the encoded content length is a multiple of 8 by padding with zeros
        while (encodedContent.size() % 8 != 0) {
            encodedContent += '0';
        }

        // Write the encoded content as bytes to the output file
        for (size_t i = 0; i < encodedContent.size(); i += 8) {
            bitset<8> byte(encodedContent.substr(i, 8)); // Convert each 8-bit chunk to a byte
            outFile.put(static_cast<unsigned char>(byte.to_ulong())); // Write the byte to the output file
        }

        inFile.close();
        outFile.close();
    }

    // Decompresses the input file and writes the result to the output file
    void decompress(const std::string& inputFileName, const std::string& outputFileName) {
        ifstream infile(inputFileName, ios::binary);
        ofstream outfile(outputFileName, ios::binary);

        if (!infile) {
            cerr << "Cannot open file: " << inputFileName << endl;
            return;
        }

        // Read the frequency table size from the input file
        size_t frequencyTableSize;
        infile.read(reinterpret_cast<char*>(&frequencyTableSize), sizeof(frequencyTableSize));
        frequency_map.clear();

        // Read the frequency table from the input file
        for (size_t i = 0; i < frequencyTableSize; ++i) {
            char ch;
            unsigned int freq;
            infile.get(ch);
            infile.read(reinterpret_cast<char*>(&freq), sizeof(freq));
            frequency_map[ch] = freq; // Rebuild the frequency map
        }

        HuffmanNode* root = buildHuffmanTree(frequency_map, theMinHeap); // Rebuild the Huffman tree
        HuffmanNode* huffmanPtr = root;
        root->decode(huffmanPtr, infile, outfile); // Decode the content using the Huffman tree

        infile.close();
        outfile.close();
    }
} // namespace compressor