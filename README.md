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
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long int;
template <class T> using binary_tree = tree<T, null_type, logical_and<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}

```