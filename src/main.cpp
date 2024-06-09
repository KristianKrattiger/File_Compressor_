/**
 * @brief Author: [Your Name]
 *
 * This file contains the implementation of a file compressor using Huffman coding.
 * The compressor provides functions to read a file, compress it using Huffman coding,
 * and decompress a file that was previously compressed using Huffman coding.
 *
 * The compressor uses a MinHeap to build the Huffman tree and stores the character
 * frequencies in a map. It also provides functions to encode and decode the Huffman tree.
 *
 * The main functions in this file are:
 * - `readFile`: Reads the contents of a file and calculates character frequencies.
 * - `compress`: Compresses a file using Huffman coding.
 * - `decompress`: Decompresses a file using Huffman coding.
 *
 * The HuffmanNode class represents a node in the Huffman tree and provides functions
 * to print the tree, encode the tree, and decode the tree.
 *
 * The MinHeap class is used to build the Huffman tree by maintaining a min-heap of nodes.
 * It provides functions to insert nodes, extract the minimum node, and get the size of the heap.
 *
 * The `frequency_map` and `HuffmanCode` maps are used to store character frequencies and
 * Huffman codes respectively.
 */

#include "compressor.h"
#include "huffman.h"
#include <iostream>
#include <filesystem>

using namespace std;
using namespace compressor;
namespace fs = std::filesystem;

int main() {
    fs::path inputFileName, outputFileName;
    char choice;

    std::cout << "|WELCOME TO THE FILE COMPRESSOR|" << std::endl
              << "--------------------------------" << std::endl;
    std::cout << "This program uses Huffman coding to compress and decompress files." << std::endl;

    while (true) {
        std::cout << "Enter the path to the file you want to compress:" << std::endl;
        std::cout << "Example: " << fs::current_path() / "example.txt" << std::endl;  // Provide an example based on the current directory
        std::cin >> inputFileName;
        inputFileName = fs::absolute(inputFileName);  // Convert to absolute path
        std::cout << readFile(inputFileName) << std::endl;

        std::cout << "Enter the path to save the compressed file:" << std::endl;
        std::cout << "Example: " << fs::current_path() / "example_compressed.bin" << std::endl;  // Provide an example
        std::cin >> outputFileName;
        outputFileName = fs::absolute(outputFileName);
        compress(inputFileName, outputFileName);
        std::cout << "File successfully compressed to " << outputFileName << std::endl;

        std::cout << "Do you want to decompress a file? (y/n): ";
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            std::cout << "Enter the path to the file you want to decompress:" << std::endl;
            std::cout << "Example: " << fs::current_path() / "example_compressed.bin" << std::endl;
            std::cin >> inputFileName;
            inputFileName = fs::absolute(inputFileName);
            std::cout << "Enter the path to save the decompressed file:" << std::endl;
            std::cout << "Example: " << fs::current_path() / "example_decompressed.txt" << std::endl;
            std::cin >> outputFileName;
            outputFileName = fs::absolute(outputFileName);
            decompress(inputFileName, outputFileName);
            std::cout << "File successfully decompressed to " << outputFileName << std::endl;
        } else {
            break;
        }
    }

    return 0;
}