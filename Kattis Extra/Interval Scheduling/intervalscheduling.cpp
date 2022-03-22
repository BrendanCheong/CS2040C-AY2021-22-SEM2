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
template <class T> using binary_tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N; cin >> N;
    ll s, f;
    multiset<pair<ll, ll>> times;

    while (N--) {
        cin >> s >> f;
        times.insert(make_pair(f, s));
    }
    ll end_time = 0, ans = 0;
    for (auto& [i, j] : times) {
        if (min(end_time, j) == end_time) {
            end_time = i;
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
