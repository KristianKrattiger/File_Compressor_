#include "fileHandles.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <filesystem>
#include <map>

using namespace std;

namespace fileHandles {
    map<char, unsigned int> frequency_map; // Map to store the frequency of each character in the file

    // Checks if a file exists at the given path
    bool fileExists(const filesystem::path& path) {
        if (!filesystem::exists(path)) {
            cout << "File does not exist: " << path << endl;
            return false;
        }
        return true;
    }
    
    // Reads a file and builds a frequency map of its characters
    void readFileHUF(const std::string& filePath) {
        cout << "Reading file: " << filePath << endl;
        ifstream inFile(filePath, ios::binary); // Open file in binary mode
        if (!inFile) {
            cerr << "Cannot open file: " << filePath << endl;
            return;
        }

        frequency_map.clear(); // Clear the frequency map before reading

        char tempChar;
        // Read the file character by character
        while (inFile.get(tempChar)) {
            frequency_map[tempChar]++; // Increment the frequency of the character
            cout << tempChar; // Print the character (optional, for debugging)
        }

        // Print the frequency of each character
        for (const auto& pair : frequency_map) {
            cout << pair.first << " " << pair.second << endl;
        }

        inFile.close();
        cout << "File successfully read.\n";
    }
}