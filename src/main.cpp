#include <cstdlib>
#include <sstream>
#include <unistd.h>
#include <iostream>
#include <string>
#include <sys/wait.h>
#include <fcntl.h> 

int main() {
    int status;
    std::string command = "";
    std::string arg = "";
    
    std::getline(std::cin, command);    
    std::getline(std::cin, arg);

    std::cout << "Executing command: " << command << std::endl;
    pid_t c_id = fork();

    if (c_id == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } 
    else if (c_id > 0) {
        //Parent Process
        while (waitpid(c_id, &status, WNOHANG) == 0) { }
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            std::cout << "Command successfully executed! :D" << std::endl;
        }
    }
    else {
        //Child Process
        //Command building...
        std::string commandStr = "/usr/bin/" + command;
        char* commandChar = &commandStr[0];
        char* argChar = arg.empty() ? nullptr : &arg[0];
        char* const args[] = {commandChar, argChar, nullptr};

        if (execv(commandChar, args) == -1) {
            std::string errMsg = std::string("Error executing command: ") + commandChar;
            perror(errMsg.c_str());
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}