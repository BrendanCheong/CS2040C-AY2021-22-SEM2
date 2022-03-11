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
    ll p, t; cin >> p >> t;
    ll i, j;
    unordered_map<ll, binary_tree<ll>> forests;
    unordered_set<string> ans_set;
    while (cin >> i && cin >> j) {
        forests[i].insert(j);
    }

    for (auto& [k, v] : forests) {
        string ans = "";
        for (size_t i = 0; i < v.size(); i++) {
            ans += *v.find_by_order(i) + ' ';
        }

        ans_set.insert(ans);
    }

    for (size_t i = 0; i < p; ++i) {
        if (!forests.count(i + 1))
            ans_set.insert("");
    }

    cout << ans_set.size() << '\n';

    return 0;
}