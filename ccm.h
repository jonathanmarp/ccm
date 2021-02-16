#ifdef __cplusplus
#include <string>

    #ifndef CCM_H
    #define CCM_H

        #ifdef _WIN32

            #include "ccm/windows.h"

        #else
            void input(std::string&, std::string);
            void ExecutableRun(std::string&);
        #endif

    #endif

#endif
