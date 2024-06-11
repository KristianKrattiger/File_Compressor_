#include "compressor.h"
#include "huffman.h"
#include "fileHandles.h"

#include <filesystem>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
using namespace compressor;
using namespace fileHandles;
namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Usage: " << argv[0] << " <compress|decompress> <input_file_path> <output_file_path>" << endl;
        return 1;
    }

    string mode = argv[1];
    string inputPath = argv[2];
    string outputPath = argv[3];
    fs::path filePath_in(inputPath);
    fs::path filePath_out(outputPath);

    // Display the current working directory
    cout << "Current Working Directory: " << fs::current_path() << endl;
    cout << "|WELCOME TO THE FILE COMPRESSOR|" << endl
         << "--------------------------------" << endl;
    cout << "This program uses Huffman coding to compress and decompress files." << endl;

    if (mode == "compress") {
        if (!fileExists(filePath_in)) {
            cout << "File does not exist: " << filePath_in << endl;
            return 1;
        }

        // Copy the input file to the current directory as "infile.txt"
        fs::copy_file(filePath_in, fs::current_path() / "infile.txt");

        cout << "Reading file from: " << filePath_in << endl;
        readFileHUF("infile.txt"); // Read the file to build the frequency map

        if (!fileExists(filePath_out)) {
            ofstream outfile(filePath_out.string());
            if (!outfile) {
                cout << "Failed to create file: " << filePath_out << endl;
                return 1;
            }
            outfile.close();
        }

        compress("infile.txt", filePath_out.string()); // Compress the file
        cout << "File successfully compressed to " << filePath_out << endl;

    } else if (mode == "decompress") {
        if (!fileExists(filePath_in)) {
            cout << "File does not exist: " << filePath_in << endl;
            return 1;
        }

        // Copy the input compressed file to the current directory as "infile.bin"
        fs::copy_file(filePath_in, fs::current_path() / "infile.bin");

        if (!fileExists(filePath_out)) {
            ofstream outfile(filePath_out.string());
            if (!outfile) {
                cout << "Failed to create file: " << filePath_out << endl;
                return 1;
            }
            outfile.close();
        }

        decompress("infile.bin", filePath_out.string()); // Decompress the file
        cout << "File successfully decompressed to " << filePath_out << endl;

    } else {
        cout << "Invalid mode. Use 'compress' or 'decompress'." << endl;
        return 1;
    }

    return 0;
}