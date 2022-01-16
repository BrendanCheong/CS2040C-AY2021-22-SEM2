# CS2040C-AY2021-22-SEM2
Ya boy is back at it again with another CS mod

## Compiling and Running Code

### Java

```
javac Java/*.java
java -cp Java/ Main < test.in
```

### Python

```
python3.10 Python/Main.py
```

### C++

```
g++ -o main.out Cpp/main.cpp
./main.out < test.in

# main being the name of the desired file name
```

# Boilerplate 

```cpp
#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
using ll = long long;

int main() 
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}

```