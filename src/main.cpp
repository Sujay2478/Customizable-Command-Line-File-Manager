#include "FileOperations.h"
#include <iostream>
#include <string>

int main() {
    std::string command, path, destination, searchQuery;

    while (true) {
        std::cout << "> ";
        std::cin >> command;

        if (command == "create") {
            std::cin >> path;
            createFile(path);
        } else if (command == "delete") {
            std::cin >> path;
            deleteFile(path);
        } else if (command == "move") {
            std::cin >> path >> destination;
            moveFile(path, destination);
        } else if (command == "mkdir") {
            std::cin >> path;
            createDirectory(path);
        } else if (command == "rmdir") {
            std::cin >> path;
            deleteDirectory(path);
        } else if (command == "ls") {
            std::cin >> path;
            listDirectory(path);
        } else if (command == "search") {
            std::cin >> path >> searchQuery;
            searchFiles(path, searchQuery);
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Unknown command." << std::endl;
        }
    }

    return 0;
}