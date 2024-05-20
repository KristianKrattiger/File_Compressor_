#include "compressor.h"
#include "MinHeap.h"
#include <iostream>

using namespace std;
using namespace compressor;

int main(){
    int input = 0;
    string filename;
    bool isValidOption = true;

    //ui
    cout << "Welcome to file comprex.\n"
    <<"Enter 1 to upload file\n\n"
    <<"Enter 2 to end program\n\n"
    <<"Enter option: ";

    cin >> input;
    cout << "\n";
    
    while(isValidOption){
        switch(input){
            case 1:
                cout << "Please enter file name with the extension: ";
                cin >> filename;
                readFile(filename);
                isValidOption = false;
                cout << "File successfully opened!\n";
                compress(filename, filename + "Compressed.txt");
                break;

            case 2:
                break;

            default:
                cout << "Please enter a valid option.\n";
                isValidOption = false;
            break;
        }
    }

    //Print map
    // for (const auto& pair : compressor::frequencyMap) {
    //     std::cout << "Character: " << pair.first << ", Frequency: " << pair.second << std::endl;
    // }
    // return 0;
}