# ccm
Library for http or socket connection to shell with encrypt. made in C++

- Step 1
Work With Shell :heavy_check_mark:

- Step 2
Make Connection :x:

# Already done
- Step1 (Work With Shell) :heavy_check_mark:
- Step2 (Color Output Shell) :heavy_check_mark:

## If There Are Bugs Or Use Could Put On Issue

```C++
#include <iostream>
#include "folder/ccm.h"

int main(int argc, const char* argv[]) {
  std::string temp;
  while(true) {
    input(temp, "$ "); // in parameter 2 its The emblem is usually on the shell
    ExecutableRun(temp);
  }
  {
    (void)argc;
    (void)argv;
  }
  return 0;
}
```

for compile

- linux
```bash
g++ -shared -Wall -fPIC file.cpp -L./folder/ccm -lccm -o nameFile
```

- windows
```bash
g++ -shared -Wall -fPIC file.cpp -L.\folder\ccm -lccm -o nameFile
```

compile in g++

- windows
```bash
g++ -shared -Wall -fPIC -DBUILD_SHARED_LIB ccm.cpp ls.cpp clear.cpp pwd.cpp exec1.cpp exec2.cpp exit.cpp color.cpp -o ccm.dll -Wl,--out-implib,libccm.a
```

- linux
```bash
g++ -shared -fPIC -Wall ccm.cpp ls.cpp color.cpp pwd.cpp exec1.cpp exec2.cpp clear.cpp exit.cpp -o libccm.so
```
