#include "ccm/CCM_Header.h"
#include "ccm/pwd.h"
#include "ccm/color.h"
#include "ccm/exec1.h"

void pwd() {
    #ifdef _WIN32
        char buffer[MAX_PATH];
        GetModuleFileNameA(NULL, buffer, MAX_PATH);
        std::string::size_type pos = std::string(buffer).find_last_of("\\/");

        std::string linkDir = std::string(buffer).substr(0, pos);
        getColor(14);
        std::cout << linkDir << std::endl;
        getColor(15);
    #else
        std::string _Briffing = exec1("pwd");
        getColor(_Buff, F_YELLOW);
        std::cout << _Briffing << std::endl;
        getColor(_Buff, reseting);
    #endif
}