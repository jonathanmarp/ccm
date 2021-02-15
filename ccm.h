#ifdef __cplusplus
#include <string>

    #ifndef CCM_H
    #define CCM_H

        #ifdef _WIN32

            #ifdef __cplusplus
                extern "C" {
            #endif

                #ifdef BUILD_SHARED_LIB
                    #define CCM __declspec(dllexport)
                #else
                    #define CCM __declspec(dllimport)
                #endif

                void CCM input(std::string&, std::string);
                void CCM ExecutableRun(std::string&);

            #ifdef __cplusplus
                }
            #endif

        #else
            void input(std::string&, std::string);
            void ExecutableRun(std::string&);
        #endif

    #endif

#endif