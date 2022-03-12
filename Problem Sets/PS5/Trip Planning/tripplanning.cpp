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
    ll N, M; cin >> N >> M;
    unordered_map<ll, map<ll, ll>> cities; // K, V: city, map of cities connected by train number
    vector<pair<ll, ll>> connections; // arr of connections to take from city to city, last element is last city to first city
    list<ll> trains; // list of trains to take
    // connect each city to city via the correct train number
    for (size_t i = 0; i < M; i++) {
        ll a, b; cin >> a >> b;
        ll index = i + 1;
        cities[a][b] = index;
        cities[b][a] = index;
    }

    for (size_t i = 0; i < N; i++) {
        ll index = i + 1;
        (i == N - 1)
            ? connections.push_back(make_pair(index, 1)) // I have to loop back to the first stop
            : connections.push_back(make_pair(index, index + 1)); // I must go from i to i + 1... n - 1 to n
    }

    for (auto& [city1, city2] : connections) {
        if (cities[city1].count(city2)) // can city1 go to city2 as dictated in the connections to take
            trains.push_back(cities[city1][city2]);
        else {
            cout << "impossible" << endl; // if the trip is broken, then print impossible
            return 0;
        }
    }
    for_each(trains.begin(), trains.end(), [](ll& train) { cout << train << '\n'; });

    return 0;
}