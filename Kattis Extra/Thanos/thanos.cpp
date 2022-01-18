#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long int;

ll infinityStones(ll p, ll r, ll f) {
    ll years = 0;
    while (true) {
        if (p > f) {
            break;
        }
        p *= r;
        ++years;
    }
    return years;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int rounds = 0;
    cin >> rounds;
    for (size_t i = 0; i < rounds; ++i)
    {
        ll p, r, f = 0;
        cin >> p >> r >> f;
        cout << infinityStones(p, r, f) << endl;
    }

    return 0;
}