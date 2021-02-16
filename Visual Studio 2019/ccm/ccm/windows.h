// Lokking if C++ in exist
// If Exist not run using C++
// this can't run this script

#ifdef __cplusplus
    extern "C"{
#endif

// TO build this with mingw32 or ming64
// g++ -c -DBUILD_SHARED_LIB ccm.cpp
// g++ -shared -Wall -fPIC -o ccm.dll ccm.o -Wl,--out-implib,libccm.a

#ifdef CCM_EXPORTS // if this visual studio change this to CCM_EXPORTS
    // Exports library
    #define CCM __declspec(dllexport)
#else
    // Importing library
    #define CCM __declspec(dllimport)
#endif
    // Input Library from CCM
    void CCM input(std::string &, std::string);

    // Run Shell And Get output from refrench string
    void CCM ExecutableRun(std::string &);

// If Not define C++ this script can't run
#ifdef __cplusplus
    }
#endif