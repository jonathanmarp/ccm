#include "ccm/CCM_Header.h"
#include "ccm/ls.h"

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