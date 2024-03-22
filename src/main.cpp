#include "FileOperations.h"
#include <iostream>
#include <string>

int main() {
    std::string command;
    std::string path1, path2;

    while (true) {
        std::cout << "> ";
        std::cin >> command;

        if (command == "create") {
            std::cin >> path1;
            createFile(path1);
        } else if (command == "delete") {
            std::cin >> path1;
            deleteFile(path1);
        } else if (command == "move") {
            std::cin >> path1 >> path2;
            moveFile(path1, path2);
        } else if (command == "mkdir") {
            std::cin >> path1;
            createDirectory(path1);
        } else if (command == "rmdir") {
            std::cin >> path1;
            deleteDirectory(path1);
        } else if (command == "ls") {
            std::cin >> path1;
            listDirectory(path1);
        } else if (command == "search") {
            std::cin >> path1 >> path2;
            searchFiles(path1, path2);
        } else if (command == "cp") {
            std::cin >> path1 >> path2;
            copyFile(path1, path2); // Assumes this is implemented in FileOperations
        } else if (command == "cpdir") {
            std::cin >> path1 >> path2;
            copyDirectory(path1, path2); // Assumes this is implemented in FileOperations
        } else if (command == "properties") {
            std::cin >> path1;
            displayProperties(path1); // Assumes this is implemented in FileOperations
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Unknown command. Please try again." << std::endl;
        }
    }

    return 0;
}