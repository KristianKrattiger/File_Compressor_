#include "compressor.h"
#include "huffman.h"
#include <iostream>

using namespace std;
using namespace compressor;

int main() {
    int input = 0;
    string filename;
    bool isValidOption = true;

    // ui
    cout << "Welcome to file comprex.\n"
         << "Enter 1 to upload file\n\n"
         << "Enter 2 to decompress a file\n\n"
         << "Enter 3 to end program\n\n"
         << "Enter option: ";

    cin >> input;
    cout << "\n";
    
    while (isValidOption) {
        switch (input) {
            case 1:
                cout << "Please enter file name without the extension (must be .txt): ";
                cin >> filename;
                cout << readFile(filename + ".txt");
                isValidOption = false;
                cout << "File successfully opened!\n";
                compress(filename + ".txt", filename + "Compressed.txt");
                cout << "File successfully compressed!\n";
                break;

            case 2:
                cout << "Please enter file name without the extension (must be .txt): ";
                cin >> filename;
                decompress(filename + ".txt", filename + "Decompressed.txt");
                cout << "File successfully decompressed!\n";
                isValidOption = false;
                break;

            case 3:
                cout << "Program ended.\n";
                isValidOption = false;
                break;

            default:
                cout << "Please enter a valid option.\n";
                cin >> input;
                break;
        }
    }

    return 0;
}