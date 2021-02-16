#include "ccm/CCM_Header.h"
#include "ccm/pwd.h"

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