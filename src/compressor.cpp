#include "compressor.h"
#include <fstream>
#include <iostream>
#include <unordered_map>


using namespace std;

namespace compressor{
    unordered_map<char, unsigned> frequencyMap;
    MinHeap firstTree;

    string readFile(const string& filePath) { 
        ifstream inFile(filePath, ios::binary); // Open in binary mode to preserve all data
        
        if (!inFile) {
            std::cerr << "Cannot open file: " << filePath << endl;
            return "";
        }

        // Read entire file into a frequency map
        char tempChar;
        while (inFile.get(tempChar)) {
            frequencyMap[tempChar]++;
        }

        inFile.close(); // Close the file
        return "File successfully read.\n";
    }

    void compress(const string& inputFileName,
                     const string& outputFileName){;
         // populate the min heap            
        for (const auto& pair : frequencyMap){ 
            HuffmanNode* newNode = new HuffmanNode(pair.first, pair.second);
            firstTree.insert(newNode);
        }
    }

    void decompressor(const string& inputFileName,
                         const string& outputFileName){
        //code
    }
}
