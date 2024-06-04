#ifndef COMPRESSOR_H
#define COMPRESSOR_H
#include "huffman.h"
#include <string>
#include<map>


namespace compressor{


    extern std::map<char, unsigned> frequencyMap;
    extern std::map<char, std::string> HuffmanCode;
    extern MinHeap theHeap;
    std::string readFile(const std::string& filePath);
   
    void compress(const std::string& inputFileName, const std::string& outputFileName);
    void decompress(const std::string& inputFileName, const std::string& outputFileName);
}


#endif