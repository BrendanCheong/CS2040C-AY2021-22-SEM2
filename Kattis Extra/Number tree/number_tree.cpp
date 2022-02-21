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

ll parent(ll i) { return i >> 1; } // i>>1 is the same as i/2
ll left(ll i) { return i << 1; } // i<<1 is the same as i*2
ll right(ll i) { return (i << 1) + 1; } // (i<<1)+1 is the same as i*2+1

void solve(ll N, string cmd) {
    ll ans = 1;
    for (char c : cmd) {
        switch (c) {
        case('L'):
            ans = left(ans);
            break;
        case('R'):
            ans = right(ans);
            break;
        }
    }

    cout << N - (ans - 1) << '\n';

}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n; string cmd = ""; cin >> n >> cmd;
    ll num_of_elements = pow(2, n + 1) - 1;
    if (cmd.length() > 0) {
        solve(num_of_elements, cmd);
    }
    else
        cout << num_of_elements << '\n';

    return 0;
}