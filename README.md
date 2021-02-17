# ccm
Library for http or socket connection to shell with encrypt. made in C++

- Step 1
Work With Shell :heavy_check_mark:

- Step 2
Make Connection :x:

- Step 3
Make connection in encrypt :x:

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
