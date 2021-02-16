#ifdef __cplusplus
#include <string>

    #ifndef CCM_H
    #define CCM_H

        #ifdef _WIN32

            #include "ccm/windows.h"

        #else
            #include "ccm/linux.h"
        #endif

    #endif

#endif
