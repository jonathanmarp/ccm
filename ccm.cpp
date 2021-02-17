#include "ccm/CCM_Header.h"
#include "ccm.h"

void input(std::string& refrench, std::string printS) {
    std::cout << printS;
    std::getline(std::cin, refrench);
}

typedef void (*voidFunction)();
typedef void (*voidFunctions)(std::vector<std::string>&);

std::array<std::string, 4> itsCommand = {
    "ls", "clear", "pwd", "exit"
};

std::array<std::string, 1> itsCommandSecond = {
    "cd"
};

std::array<std::string, 4> itsProgranREPL = {
    "node", "python3", "python", "zsh"
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

// include header for cd
#include "ccm/cd.h"

class itsProgram {
    private:
        bool run = false;
        std::map<std::string, voidFunction> myVoid;
        std::map<std::string, voidFunctions> myVoidParam;
        void Register() {
            this->myVoid["ls"] = ls;
            this->myVoid["clear"] = clear;
            this->myVoid["pwd"] = pwd;
            this->myVoid["exit"] = exit;

            this->myVoidParam["cd"] = cd;
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
                int bct = 1;
                for(unsigned int i = 0; i < sizeof(itsCommand) / sizeof(std::string); i++) {
                    if(exece == itsCommand[i]) {
                        itsCommands = true;
                        bct = 1;
                        break;
                    }
                }
                if(itsCommands == false) {
                    std::vector<std::string> pwrt;
                    std::string delimiter = " ";
                    size_t pos = 0;
                    std::string token;
                    while ((pos = exece.find(delimiter)) != std::string::npos) {
                        token = exece.substr(0, pos);
                        pwrt.push_back(token);
                        exece.erase(0, pos + delimiter.length());
                    }
                    pwrt.push_back(exece);
                    for(unsigned int i = 0; i < sizeof(std::string) / sizeof(itsCommandSecond); i++) {
                        if(pwrt[0] == itsCommandSecond[i]) {
                            itsCommands = true;
                            bct = 2;
                            break;
                        }
                    }
                    this->myVoidParam[pwrt[0]](pwrt);
                }
                if(itsCommands == true) {
                    if(bct == 1) {
                        this->myVoid[exece]();
                    }
                } else {
                    bool Its = false;
                    for(unsigned int i = 0; i < sizeof(itsProgranREPL) / sizeof(std::string); i++) {
                        if(itsProgranREPL[i] == exece) {
                            Its = true;
                            break;
                        }
                    }
                    if(Its == true) {
                        system(exece.c_str());
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
        }
};

void ExecutableRun(std::string& command) {
    itsProgram* trdc = new itsProgram();
    trdc->Take(command);
}