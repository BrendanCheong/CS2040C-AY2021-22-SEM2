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
    // this time I will use pair<ll, ll> to decide whether to print set or reset based on pair.second 
    ll N, Q; cin >> N >> Q;
    pair<ll, ll> reset = { 0, 0 }; // value, priority
    vector<pair<ll, ll>> people; // value, priority, index is [i-1]
    for (size_t i = 0; i < N; i++) {
        people.push_back({ 0, 0 });
    }
    ll curr_priority = 0;
    while (Q--) {
        string cmd; cin >> cmd;
        curr_priority++;
        switch (cmd[0]) {
        case('S'):
            ll i, wealth; cin >> i >> wealth;
            people[i - 1] = { wealth, curr_priority }; // set people
            break;
        case('R'):
            ll restart; cin >> restart;
            reset = { restart, curr_priority };
            break;
        default:
            ll person; cin >> person; // decide to print set value or restart value
            ll index = person - 1;
            ll priority = people[index].second;
            // cout << "reset priority: " << '<' << reset.first << ',' << reset.second << '>' << '\n';
            // cout << "person: " << '<' << people[index].first << ',' << priority << '>' << '\n';
            if (priority < reset.second)
                cout << reset.first << '\n';
            else
                cout << people[index].first << '\n';
            break;
        }
    }

    return 0;
}