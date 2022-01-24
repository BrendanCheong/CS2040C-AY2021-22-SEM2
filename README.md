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
g++ -o main.out --std c++17 main.cpp
./main.out < test.in

# main being the name of the desired file name
```

# Boilerplate 

```cpp
/**
 * Matric: A0217988E
 * Name: Brendan Cheong Ern Jie
 * Lab: 10
 * TA: Fidella Widjojo
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
using ull = unsigned long long int;

int main() 
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}

```