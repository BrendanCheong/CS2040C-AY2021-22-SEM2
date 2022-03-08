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
template <class T> using pq = std::priority_queue<T>;
template <class T> using binary_tree = tree<T, null_type, logical_and<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min

ll solve(map<ll, pq<ll>>& dict, ll X) {
    ll count = 0;
    while (!dict.empty()) { // Repeat steps with remaining amount of energy, until energy left becomes 0, or there are no more quests to be cleared
        auto it = dict.lower_bound(X); // find the first occurence of the energy level which is equal or just smaller than X, MAY NOT be exact
        if (it == dict.end())
            it = prev(it, 1); // if at the end, no quests has energy required equal or bigger than X
        ll energy = it->first;
        while (energy > X && it != dict.begin()) { // find occurence of energy level which is equal or smaller than X if not exact
            it = prev(it, 1);
            energy = it->first;
        }
        // !NOTE: doing this causes memory issues: pq<ll> queue = it->second;
        if (energy > X) // find occurence of energy level which is equal or smaller than X if not exact
            break;
        count += it->second.top(); // by the largest gold reward
        it->second.pop(); // add up the gold reward G earned this session
        X -= energy; // Reduce energy X by E of the quest
        if (it->second.size() == 0) // Clear the quest, removing it from current pool, only clear when the queue is empty, where there is no more gold left for this quest
            dict.erase(it);
    }

    return count;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<ll, pq<ll>> dict;
    ll N; cin >> N;

    for (size_t i = 0; i < N; i++) {
        string cmd; cin >> cmd;
        switch (cmd[0]) {
        case('a'):
            ll energy, gold; cin >> energy >> gold;
            if (!dict.count(energy))
                dict[energy] = pq<ll>();
            dict[energy].push(gold);
            break;
        default:
            ll e; cin >> e;
            cout << solve(dict, e) << '\n';
            break;
        }
    }

    return 0;
}