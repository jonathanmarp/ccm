#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <memory>
#include <cstdio>
#include <stdexcept>
#include <map>
#include <array>
#ifdef _WIN32
    #include <direct.h>
    #include <Windows.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #include <dirent.h>
    #define GetCurrentDir getcwd
 #endif
#include "ccm.h"

void input(std::string& refrench, std::string printS) {
    std::cout << printS;
    std::getline(std::cin, refrench);
}

typedef void (*voidFunction)();

std::array<std::string, 4> itsCommand = {
    "ls", "clear", "pwd", "exit"
};

std::string exec1(const char* cmd) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

std::string exec2(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

void ls() {
    
    char cCurrentPath[FILENAME_MAX];

    if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath))) {
        std::cout << "Error" << std::endl;
        return;
    }

    cCurrentPath[sizeof(cCurrentPath) - 1] = '\0';

    #ifdef _WIN32
        system("dir");
    #else
        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir (cCurrentPath)) != NULL) {
            /* print all the files and directories within directory */
            while ((ent = readdir (dir)) != NULL) {
                printf ("%s\n", ent->d_name);
            }
            closedir (dir);
        } else {
            /* could not open directory */
            perror ("");
            return;
        }
    #endif
}

void clear() {
    #ifdef _WIN32
        system("cls");
    #else
        std::cout << "\033[2J\033[1;1H" << std::endl;
    #endif
}

void pwd() {
    #ifdef _WIN32
        char buffer[MAX_PATH];
        GetModuleFileNameA(NULL, buffer, MAX_PATH);
        std::string::size_type pos = std::string(buffer).find_last_of("\\/");

        std::string linkDir = std::string(buffer).substr(0, pos);
        std::cout << linkDir << std::endl;
    #else
        system("pwd");
    #endif
}

void exit() {
    #ifdef _WIN32
        std::exit(0);
    #else
        std::exit(0);
    #endif
}

class itsProgram {
    private:
        bool run = false;
        std::map<std::string, voidFunction> myVoid;
        void Register() {
            this->myVoid["ls"] = ls;
            this->myVoid["clear"] = clear;
            this->myVoid["pwd"] = pwd;
            this->myVoid["exit"] = exit;
        }
    public:
        itsProgram()
            : run(true) {
                this->Register();
            }
        void Take(std::string& exece) {
            if(this->run == false) {
                std::cout << "error" << std::endl;
                return;
            } else {
                bool itsCommands = false;
                for(int i = 0; i < sizeof(itsCommand) / sizeof(std::string); i++) {
                    if(exece == itsCommand[i]) {
                        itsCommands = true;
                    }
                }
                if(itsCommands == true) {
                    this->myVoid[exece]();
                } else {
                    bool runOk = false;
                    try {
                        std::cout << exec1(exece.c_str()) << std::endl;
                        runOk = true;
                    } catch(...) {
                        try {
                            std::cout << exec2(exece.c_str()) << std::endl;
                            runOk = true;
                        } catch(...) {
                            runOk = false;
                        }
                    }
                    if(runOk == false) {
                        std::cout << "Error " << exece << std::endl;
                    }
                }
            }
        }
};

void ExecutableRun(std::string& command) {
    itsProgram* trdc = new itsProgram();
    trdc->Take(command);
}