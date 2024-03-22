#include "FileOperations.h"
#include <iostream>
#include <string>

int main() {
    std::string command, fileName, source, destination;

    while (true) {
        std::cout << "> ";
        std::cin >> command;

        if (command == "create") {
            std::cin >> fileName;
            createFile(fileName);
        } else if (command == "delete") {
            std::cin >> fileName;
            deleteFile(fileName);
        } else if (command == "move") {
            std::cin >> source >> destination;
            moveFile(source, destination);
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Unknown command." << std::endl;
        }
    }

    return 0;
}