#include "ccm/CCM_Header.h"
#include "ccm/ls.h"
#include "ccm/color.h"

void ls() {
    
    char cCurrentPath[FILENAME_MAX];

    if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath))) {
        std::cout << "Error" << std::endl;
        return;
    }

    cCurrentPath[sizeof(cCurrentPath) - 1] = '\0';

    #ifdef _WIN32
        getColor(14);
        system("dir");
        getColor(15);
    #else
        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir (cCurrentPath)) != NULL) {
            /* print all the files and directories within directory */
            while ((ent = readdir (dir)) != NULL) {
                std::string _Buffing = ent->d_name;
                getColor(_Buffing, F_YELLOW);
                printf ("%s\n", _Buffing.c_str());
                getColor(_Buff, reseting);
            }
            closedir (dir);
        } else {
            /* could not open directory */
            perror ("");
            return;
        }
    #endif
}