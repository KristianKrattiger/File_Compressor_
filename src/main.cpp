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


using namespace std;
using namespace compressor;

int main() {
    int input = 0;
    string filename;
    bool isValidOption = true, done = true;

    // ui
    // cout << "Welcome to file comprex.\n"
    //      << "Enter 1 to upload file\n\n"
    //      << "Enter 2 to decompress a file\n\n"
    //      << "Enter 3 to end program\n\n"
    //      << "Enter option: ";

   
    // do{
    //     cin >> input;
    //     cout << "\n";
    //     while (isValidOption) {
    //         switch (input) {
    //             case 1:
    //                 cout << "Please enter file name without the extension (must be .txt): ";
    //                 cin >> filename;
    //                 cout << readFile(filename + ".txt");
    //                 isValidOption = false;
    //                 cout << "File successfully opened!\n";
    //                 compress(filename + ".txt", filename + "Compressed.txt");
    //                 cout << "File successfully compressed!\n";
    //                 break;


    //             case 2:
    //                 cout << "Please enter file name without the extension (must be .txt): ";
    //                 cin >> filename;
    //                 decompress(filename + ".txt", filename + "Decompressed.txt");
    //                 cout << "File successfully decompressed!\n";
    //                 isValidOption = false;
    //                 break;

    //             case 3:
    //                 cout << "Program ended.\n";
    //                 isValidOption = false;
    //                 done = false;
    //                 break;


    //             default:
    //                 cout << "Please enter a valid option.\n";
    //                 cin >> input;
    //                 break;
    //         }
    //     }
    //     cout << "Enter 1 to upload file\n\n"
    //          << "Enter 2 to decompress a file\n\n"
    //          << "Enter 3 to end program\n\n"
    //          << "Enter option: ";
    //          isValidOption = true;
    // } while(done);

    cout << readFile("alice29.txt");
    compress("alice29.txt", "alice29Compressed.txt");
    decompress("alice29Compressed.txt", "alice29Decompressed.txt");

    return 0;
}