#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long int;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define INF 0x3f3f3f3f

ll max_nodes(ll h) {
    return pow(2, h + 1) - 1;
}

ll min_nodes(ll h) {
    if (h == 0) {
        return 1;
    }
    else if (h == 1) {
        return 2;
    }
    else {
        return min_nodes(h - 2) + min_nodes(h - 1) + 1;
    }
}

ull factorial(ll n) {
    ull fact = 1;
    for (ull i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

ll catalan(ll h) {
    //(2n)!/(n+1)! n!
    return factorial(2 * h) / ((factorial(h + 1) * factorial(h)));

    //Did it for you.
}

int main() {

    int height = 10; //change this value here.

    cout << "Max number of nodes in BBST of height " << height << ": " << max_nodes(height) << '\n';
    cout << "Min number of nodes in BBST of height " << height << ": " << min_nodes(height) << '\n';
    cout << "Maximum number of combinations of UNBALANCED BST of height " << height << ": " << catalan(height) << '\n'; //! NOTE: max height is 10 any higher is WRONG ANS

}