g++ -ffast-math -fstack-arrays -fmax-stack-var-size=100000 -fno-protect-parens -foptimize-strlen -foptimize-sibling-calls -shared -Wall -fPIC -DBUILD_SHARED_LIB ccm.cpp ls.cpp clear.cpp pwd.cpp exec1.cpp exec2.cpp exit.cpp color.cpp cd.cpp -o ccm.dll -Wl,--out-implib,libccm.a
