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

int main() {
    string inputPath, outputPath;
    char choice;

    // Display the current working directory
    cout << "Current Working Directory: " << fs::current_path() << endl;
    cout << "|WELCOME TO THE FILE COMPRESSOR|" << endl
         << "--------------------------------" << endl;
    cout << "This program uses Huffman coding to compress and decompress files." << endl;

    while (true) {
        cout << "Enter the path to the file you want to compress" << endl;
        cout << "Example: C:\\Users\\your_name\\Documents\\example.txt" << endl;
        cout << "File path: ";
        getline(cin, inputPath); // Get the input file path from the user
        fs::path filePath_in(inputPath);
               
        if (!fileExists(filePath_in)) {
            cout << "File does not exist. Please try again." << endl;
            continue; // Prompt user again if file does not exist
        }

        // Copy the input file to the current directory as "infile.txt"
        fs::copy_file(filePath_in, fs::current_path() / "infile.txt");

        cout << "Reading file from: " << filePath_in << endl;
        readFileHUF("infile.txt"); // Read the file to build the frequency map
        cout << endl;

        cout << "Enter the path to save the compressed file:" << endl;
        cout << "Example: C:\\Users\\your_name\\Documents\\example_compressed.bin" << endl;
        getline(cin, outputPath); // Get the output file path from the user
        fs::path filePath_out(outputPath);
        string outfileName = filePath_out.string();

        if (!fileExists(filePath_out)) {
            char createFile;
            cout << "File does not exist: " << filePath_out << endl;
            cout << "Would you like to create the file? (y/n): ";
            cin >> createFile;
            cin.ignore(); // Clear the newline character left in the buffer
            if (createFile == 'y' || createFile == 'Y') {
                ofstream outfile(outfileName);
                if (!outfile) {
                    cout << "Failed to create file. Please try again." << endl;
                    continue;
                }
                outfile.close();
            } else {
                continue;
            }
        }

        compress("infile.txt", outfileName); // Compress the file
        cout << "File successfully compressed to " << outfileName << endl;

        cout << "Do you want to decompress a file? (y/n): ";
        cin >> choice;
        cin.ignore(); // Clear the newline character left in the buffer
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter the path to the file you want to decompress:" << endl;
            cout << "Example: C:\\Users\\your_name\\Documents\\example_compressed.bin" << endl;
            getline(cin, inputPath); // Get the input file path for decompression
            fs::path filePath_Din(inputPath);

            if (!fileExists(filePath_Din)) {
                cout << "File does not exist. Please try again." << endl;
                continue; // Prompt user again if file does not exist
            }

            // Copy the input compressed file to the current directory as "infile.bin"
            fs::copy_file(filePath_Din, fs::current_path() / "infile.bin");

            cout << "Enter the path to save the decompressed file:" << endl;
            cout << "Example: C:\\Users\\your_name\\Documents\\example_decompressed.txt" << endl;
            getline(cin, outputPath); // Get the output file path for decompression
            fs::path filePath_Dout(outputPath);
            string DoutfileName = filePath_Dout.string();

            if (!fileExists(filePath_Dout)) {
                char createFile;
                cout << "File does not exist: " << filePath_Dout << endl;
                cout << "Would you like to create the file? (y/n): ";
                cin >> createFile;
                cin.ignore(); // Clear the newline character left in the buffer
                if (createFile == 'y' || createFile == 'Y') {
                    ofstream outfile(DoutfileName);
                    if (!outfile) {
                        cout << "Failed to create file. Please try again." << endl;
                        continue;
                    }
                    outfile.close();
                } else {
                    continue;
                }
            }

            decompress("infile.bin", DoutfileName); // Decompress the file
            cout << "File successfully decompressed to " << DoutfileName << endl;
        } else {
            break; // Exit the loop if the user does not want to decompress a file
        }
    }

    return 0;
}
