#pragma once
#include "MinHeap.h"
#include <string>
#include<unordered_map>

namespace compressor{
    extern std::unordered_map<char, unsigned> frequencyMap;
    extern MinHeap firstTree;
    std::string readFile(const std::string& filePath);

    void compress(const std::string& inputFileName, const std::string& outputFileName);
    void decompressor(const std::string& inputFileName, const std::string& outputFileName);
}