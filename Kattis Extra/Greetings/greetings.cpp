/**
 * Matric: A0217988E
 * Name: Brendan Cheong Ern Jie
 * Lab: 10
 * TA: Fidella Widjojo
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long int;

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string msg; cin >> msg;
    string ans = "";
    for (size_t i = 0; i < (msg.size() - 2) * 2; ++i) {
        ans += 'e';
    }
    cout << 'h' << ans << 'y' << endl;

    return 0;
}