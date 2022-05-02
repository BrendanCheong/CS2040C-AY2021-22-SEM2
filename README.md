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
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long int;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define INF 10e15
template <class T> using binary_tree = tree<T, null_type, logical_and<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min

// print out vector
void printVector(vll& v) {
    ll N = v.size();
    cout << '[';
    if (!N) cout << ']';
    for (size_t i = 0; i < N; i++) {
        cout << v[i];
        (i == (N - 1)) ? cout << ']' : cout << ", ";
    }
    cout << '\n';
}

// print a vector of vectors
void printVectorOfVectors(vector<vll>& v) {
    ll N = v.size();
    for (size_t i = 0; i < N; i++) {
        cout << "index: " << i << ' ';
        printVector(v[i]);
    }
    cout << '\n';
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}

```