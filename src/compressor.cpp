#include "compressor.h"
#include "huffman.h"
#include <fstream>
#include <iostream>
#include <map>
#include <bitset>

using namespace std;
namespace compressor {
    map<char, unsigned int> frequency_map;
    map<char, string> HuffmanCode;
    MinHeap theMinHeap;

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

        return minHeap.extractMin();
    }

    void compress(const std::string& inputFileName, const std::string& outputFileName) {
        cout << "\nBuilding the Huffman tree...\n";
        HuffmanNode* root = buildHuffmanTree(frequency_map, theMinHeap);
        cout << "\nHuffman tree built.\n";
        root->printTree(root);

        cout << "\nEncoding the Huffman tree...\n";
        root->encode("", HuffmanCode);
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
            encodedContent += HuffmanCode[tempChar];
        }

        while (encodedContent.size() % 8 != 0) {
            encodedContent += '0';
        }

        for (size_t i = 0; i < encodedContent.size(); i += 8) {
            bitset<8> byte(encodedContent.substr(i, 8));
            outFile.put(static_cast<unsigned char>(byte.to_ulong()));
        }

        inFile.close();
        outFile.close();
    }

    void decompress(const std::string& inputFileName, const std::string& outputFileName) {
        ifstream infile(inputFileName, ios::binary);
        ofstream outfile(outputFileName, ios::binary);

        if (!infile) {
            cerr << "Cannot open file: " << inputFileName << endl;
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