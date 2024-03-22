#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <string>

void createFile(const std::string& fileName);
void deleteFile(const std::string& fileName);
void moveFile(const std::string& source, const std::string& destination);

void createDirectory(const std::string& dirName);
void deleteDirectory(const std::string& dirName);
void listDirectory(const std::string& dirName);

void searchFiles(const std::string& dirName, const std::string& searchQuery);

void copyFile(const std::string& source, const std::string& destination);
void copyDirectory(const std::string& source, const std::string& destination);

void displayProperties(const std::string& path);

#endif