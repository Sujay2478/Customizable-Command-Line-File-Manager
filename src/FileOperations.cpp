#include "FileOperations.h"
#include <fstream>
#include <iostream>
#include <chrono>
#include <iomanip>

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
    try {
        if (fs::remove_all(dirName) > 0) {
            std::cout << "Directory deleted: " << dirName << std::endl;
        } else {
            std::cerr << "Error: Directory is not empty or does not exist: " << dirName << std::endl;
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
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

void copyFile(const std::string& source, const std::string& destination) {
    try {
        fs::copy_file(source, destination, fs::copy_options::overwrite_existing);
        std::cout << "File copied from " << source << " to " << destination << std::endl;
    } catch (const fs::filesystem_error& e) {
        std::cerr << e.what() << std::endl;
    }
}

void copyDirectory(const std::string& source, const std::string& destination) {
    try {
        fs::copy(source, destination, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
        std::cout << "Directory copied from " << source << " to " << destination << std::endl;
    } catch (const fs::filesystem_error& e) {
        std::cerr << e.what() << std::endl;
    }
}

void displayProperties(const std::string& path) {
    try {
        fs::path p(path);
        if (fs::exists(p)) {
            auto ftime = fs::last_write_time(p);
            auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
                ftime - fs::file_time_type::clock::now() + std::chrono::system_clock::now()
            );
            std::time_t cftime = std::chrono::system_clock::to_time_t(sctp);
            std::cout << "File path: " << p << std::endl;
            std::cout << "File size: " << fs::file_size(p) << " bytes" << std::endl;
            std::cout << "Last write time: " << std::put_time(std::localtime(&cftime), "%F %T") << std::endl;
        } else {
            std::cerr << "Error: Path does not exist: " << p << std::endl;
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << e.what() << std::endl;
    }
}

#else
#error
#endif

