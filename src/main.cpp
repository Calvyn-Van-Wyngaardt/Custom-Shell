#include <cstdlib>
#include <sstream>
#include <unistd.h>
#include <iostream>
#include <string>
#include <sys/wait.h>
#include <fcntl.h> 

int main() {
    int fd;             //Used for opening file
    int status;         

    std::string command = "";
    std::string arg = "";
    
    std::getline(std::cin, command);    
    std::getline(std::cin, arg);

    std::cout << "Executing command: " << command << std::endl;
    pid_t c_id = fork();        //Creating a child process

    if (c_id == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } 
    else if (c_id > 0) {
        std::cout << "Printed from parent process :) " << getpid() << std::endl;
        while (waitpid(c_id, &status, WNOHANG) == 0) { }
    }
    else {
        std::cout << "Printed from child process :D " << getpid() << std::endl;
        fd = open("abc.log", O_WRONLY | O_CREAT | O_TRUNC, 0644);

        if (fd == -1) {
            perror("Could not open file...");
            return 1;
        }

        //stdout
        if (close(1) == -1) {
            perror("Error closing stdout");
            return 1;
        }

        if (dup2(fd, 1) == -1) {
            perror("Error copying fd to stdout");
            return 1;
        }

        //stderr
        if (close(2) == -1) {
            perror("Error closing stderr");
            return 1;
        }

        if (dup2(fd, 2) == -1) {
            perror("Error copying fd to stderr");
            return 1;
        }
        
        //Command building...
        std::string commandStr = "/usr/bin/" + command;
        char* commandChar = &commandStr[0];
        char* argChar = &arg[0];
        char* const args[] = {commandChar, argChar, nullptr};

        if (execv(commandChar, args) == -1) {
            std::string errMsg = std::string("Error executing command: ") + commandChar;
            perror(errMsg.c_str());
            return 1;
        }

        //Write operations...
        std::cout << "Command successsfully executed! :D" << std::endl;

        close(fd);
    }

    return 0;
}