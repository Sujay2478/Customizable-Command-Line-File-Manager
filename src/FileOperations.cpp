#include "FileOperations.h"
#include <fstream>
#include <iostream>

void createFile(const std::string& fileName) {
    std::ofstream file(fileName);
    if (file) {
        std::cout << "File created: " << fileName << std::endl;
    } else {
        std::cerr << "Error creating file: " << fileName << std::endl;
    }
}

void deleteFile(const std::string& fileName) {
    if (std::remove(fileName.c_str()) == 0) {
        std::cout << "File deleted: " << fileName << std::endl;
    } else {
        std::cerr << "Error deleting file: " << fileName << std::endl;
    }
}

void moveFile(const std::string& source, const std::string& destination) {
    if (std::rename(source.c_str(), destination.c_str()) == 0) {
        std::cout << "File moved from " << source << " to " << destination << std::endl;
    } else {
        std::cerr << "Error moving file from " << source << " to " << destination << std::endl;
    }
}

