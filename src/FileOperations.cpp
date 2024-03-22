#include "FileOperations.h"
#include <fstream>
#include <iostream>

#if __cplusplus >= 201703L
#include <filesystem>
namespace fs = std::filesystem;

void createDirectory(const std::string& dirName) {
    if (fs::create_directory(dirName)) {
        std::cout << "Directory created: " << dirName << std::endl;
    } else {
        std::cerr << "Error creating directory: " << dirName << std::endl;
    }
}

void deleteDirectory(const std::string& dirName) {
    if (fs::remove_all(dirName)) {
        std::cout << "Directory deleted: " << dirName << std::endl;
    } else {
        std::cerr << "Error deleting directory: " << dirName << std::endl;
    }
}

void listDirectory(const std::string& dirName) {
    if (fs::exists(dirName) && fs::is_directory(dirName)) {
        for (const auto& entry : fs::directory_iterator(dirName)) {
            std::cout << entry.path() << std::endl;
        }
    } else {
        std::cerr << "Error: Directory does not exist or is not a directory: " << dirName << std::endl;
    }
}

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

void searchFiles(const std::string& dirName, const std::string& searchQuery) {
    if (fs::exists(dirName) && fs::is_directory(dirName)) {
        for (const auto& entry : fs::recursive_directory_iterator(dirName)) {
            if (entry.path().filename().string().find(searchQuery) != std::string::npos) {
                std::cout << entry.path() << std::endl;
            }
        }
    } else {
        std::cerr << "Error: Directory does not exist or is not a directory: " << dirName << std::endl;
    }
}

#else
#error
#endif

