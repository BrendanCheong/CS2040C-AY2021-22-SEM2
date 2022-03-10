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

ll solve(ll N) {
    set<ll> guests;
    for (size_t i = 0; i < N; i++) {
        ll person; cin >> person;
        if (guests.count(person))
            guests.erase(person);
        else
            guests.insert(person);
    }
    auto it = guests.begin();

    return *it;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n; cin >> n;
    for (size_t _ = 0; _ < n; _++) {
        ll m; cin >> m;
        cout << "Case #" << _ + 1 << ": " << solve(m) << '\n';
    }

    return 0;
}