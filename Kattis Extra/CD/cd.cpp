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
    ll N, M; cin >> N >> M;
    ll cd;
    while (N > 0 || M > 0) {
        ll ans = 0; unordered_set<ll> set;
        for (size_t i = 0; i < N; i++) {
            cin >> cd;
            set.insert(cd);
        }
        for (size_t i = 0; i < M; i++) {
            cin >> cd;
            if (set.find(cd) != set.end()) {
                ans++;
            }
        }
        cout << ans << endl;
        cin >> N >> M;
    }
    return 0;
}