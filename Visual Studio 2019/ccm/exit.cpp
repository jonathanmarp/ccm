#include "pch.h"
#include "ccm/CCM_Header.h"
#include "ccm/exit.h"

void exit() {
    #ifdef _WIN32
        std::exit(0);
    #else
        std::exit(0);
    #endif
}