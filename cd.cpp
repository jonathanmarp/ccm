#include "ccm/CCM_Header.h"
#include "ccm/cd.h"

void cd(std::vector<std::string>& prms) {
    #ifdef _WIN32
        SetCurrentDirectoryA(prms[1].c_str());
    #else
        chdir(prms[1].c_str());
    #endif
}