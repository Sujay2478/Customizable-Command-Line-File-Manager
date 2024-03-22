#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <string>

void createFile(const std::string& fileName);
void deleteFile(const std::string& fileName);
void moveFile(const std::string& source, const std::string& destination);

#endif