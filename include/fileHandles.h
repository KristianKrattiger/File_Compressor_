#ifndef FILE_HANDLES_H
#define FILE_HANDLES_H

#include <filesystem>
#include <fstream>
#include <map>
#include <string>

namespace fileHandles {
    //variables for handling data
    extern std::map<char, unsigned int> frequency_map;
    extern std::string data;

    //function prototypes
    bool fileExists(const std::filesystem::path& path);
    std::string correctPath(const std::string& pathStr);
    void readFileHUF(const std::string& filePath);
};

#endif
