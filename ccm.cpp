#include "ccm/CCM_Header.h"
#include "ccm.h"

void input(std::string& refrench, std::string printS) {
    std::cout << printS;
    std::getline(std::cin, refrench);
}

typedef void (*voidFunction)();

std::array<std::string, 4> itsCommand = {
    "ls", "clear", "pwd", "exit"
};

// including header for exec1
#include "ccm/exec1.h"

// including header for exec2
#include "ccm/exec2.h"

// including header ls
#include "ccm/ls.h"

// including header for clear
#include "ccm/clear.h"

// include header for pwd
#include "ccm/pwd.h"

// include header for exit
#include "ccm/exit.h"

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
                for(unsigned int i = 0; i < sizeof(itsCommand) / sizeof(std::string); i++) {
                    if(exece == itsCommand[i]) {
                        itsCommands = true;
                    }
                }
                if(itsCommands == true) {
                    this->myVoid[exece]();
                } else {
                    bool runOk = false;
                    #include "ccm/color.h"
                    try {
                        std::string _Buff = exec1(exece.c_str());
                        #ifdef _WIN32
                            getColor(14);
                        #else
                            getColor(_Buff, F_YELLOW);
                        #endif
                        std::cout << _Buff << std::endl;
                        #ifdef _WIN32
                            getColor(15);
                        #else
                            getColor(_Buff, reseting);
                        #endif
                        runOk = true;
                    } catch(...) {
                        try {
                            std::string _Buff = exec2(exece.c_str());
                            #ifdef _WIN32
                                getColor(14);
                            #else
                                getColor(_Buff, F_YELLOW);
                            #endif
                            std::cout << _Buff << std::endl;
                            #ifdef _WIN32
                                getColor(15);
                            #else
                                getColor(_Buff, reseting);
                            #endif
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