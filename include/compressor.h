#ifndef COMPRESSOR_H
#define COMPRESSOR_H
#include "huffman.h"
#include <string>
#include<map>

/**
 * @namespace compressor
 * @brief Namespace containing functions and data structures for file compression and decompression.
 */
namespace compressor{

    /**
     * @brief Map to store the frequency of each character in the input file.
     */
    extern std::map<char, unsigned> frequencyMap;

    /**
     * @brief Map to store the Huffman code for each character in the input file.
     */
    extern std::map<char, std::string> HuffmanCode;

    /**
     * @brief MinHeap data structure used for building the Huffman tree.
     */
    extern MinHeap theHeap;

    /**
     * @brief Reads the contents of a file and returns it as a string.
     * @param filePath The path to the input file.
     * @return The contents of the file as a string.
     */
    std::string readFile(const std::string& filePath);
   
    /**
     * @brief Compresses the input file using Huffman coding and writes the compressed data to the output file.
     * @param inputFileName The path to the input file.
     * @param outputFileName The path to the output file.
     */
    void compress(const std::string& inputFileName, const std::string& outputFileName);

    /**
     * @brief Decompresses the input file using Huffman coding and writes the decompressed data to the output file.
     * @param inputFileName The path to the input file.
     * @param outputFileName The path to the output file.
     */
    void decompress(const std::string& inputFileName, const std::string& outputFileName);
}

#endif