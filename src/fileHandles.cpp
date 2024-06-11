#include "fileHandles.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <filesystem>
#include <map>

using namespace std;

namespace fileHandles {
    map<char, unsigned int> frequency_map;

    bool fileExists(const filesystem::path& path) {
        if (!filesystem::exists(path)) {
            cout << "File does not exist: " << path << endl;
            return false;
        }
        return true;
    }

    void writeBinaryFile(const std::string& filename, const char* data, size_t dataSize) {
        std::ofstream outFile(filename, std::ios::binary | std::ios::out);
        if (!outFile) {
            std::cerr << "Cannot open file: " << filename << std::endl;
            return;
        }
        outFile.write(data, dataSize);
        outFile.close();
    }

    void readFile(const std::string& filePath) {
        cout << "Reading file: " << filePath << endl;
        ifstream inFile(filePath, ios::binary);
        if (!inFile) {
            cerr << "Cannot open file: " << filePath << endl;
            return;
        }

        frequency_map.clear();

        char tempChar;
        while (inFile.get(tempChar)) {
            frequency_map[tempChar]++;
            cout << tempChar;
        }

        for (const auto& pair : frequency_map) {
            cout << pair.first << " " << pair.second << endl;
        }

        inFile.close();
        cout << "File successfully read.\n";
    }
}