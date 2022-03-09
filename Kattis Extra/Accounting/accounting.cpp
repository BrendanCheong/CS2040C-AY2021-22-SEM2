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
    // you dont actually have to record every N people there is 
    // or you can using 2 vectors with pair<ll, ll> to decide whether to print
    // restart value or the set value, with pair.first deciding which one has priority
    ll N, Q; cin >> N >> Q;
    unordered_map<ll, ll> people; // cache to store the people who have been added
    ll restart_val = 0; // default is 0 amount
    while (Q--) {
        string cmd; cin >> cmd;
        switch (cmd[0]) {
        case('S'):
            ll i, wealth; cin >> i >> wealth;
            people[i] = wealth; // set people
            break;
        case('R'):
            ll restart; cin >> restart;
            people.clear(); // reset cache because its reset.
            restart_val = restart; // if update default restart from 0 to new number
            break;
        default:
            ll person; cin >> person; // decide to print set value or restart value
            people.count(person) // if not in cache then its the default value
                ? cout << people[person] << '\n'
                : cout << restart_val << '\n';
            break;
        }
    }
    // algo runs in O(Q) time

    return 0;
}