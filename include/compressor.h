#pragma once
#include <string>
#include <iostream>

namespace compressor{
    void compress(const std::string& inputFileName, const std::string& outputFileName);

    void decompressor(const std::string& inputFileName, const std::string& outputFileName);
}