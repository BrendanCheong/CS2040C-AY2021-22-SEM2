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
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define INF 0x3f3f3f3f
template <class T> using binary_tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min
enum { START = 0, END = 1 };

// print out vector
void printVector(vll& v) {
    ll N = v.size();
    cout << '[';
    if (!N) cout << ']';
    for (size_t i = 0; i < N; i++) {
        cout << v[i];
        (i == (N - 1)) ? cout << ']' : cout << ", ";
    }
    cout << '\n';
}

// print a vector of vectors
void printVectorOfVectors(vector<vll>& v) {
    ll N = v.size();
    for (size_t i = 0; i < N; i++) {
        cout << "index: " << i << ' ';
        printVector(v[i]);
    }
    cout << '\n';
}


void multisourceBFS(vector<vll>& AL, queue<ll>& qu, vll& dist, vector<bool>& visited, vll& source, ll& limit_day) {
    while (!qu.empty()) {
        ll k = qu.front();
        qu.pop();

        for (auto& i : AL[k]) {
            if (!visited[i]) {
                // push the adjacent unvisited vertices
                // with distance from current source = this
                // vertex's distance + 1
                qu.push(i);
                dist[i] = dist[k] + 1;
                // days[dist[k] + 1].push_back(i); // optional, updates the number of days corresponding to distance
                if (dist[k] + 1 <= limit_day && dist[k] + 1 > 0) // add to the source, where the infection started
                    source.push_back(i);
                visited[i] = true;
            }
        }
    }
}

void nearestToMaxNode(vector<vll>& AL, vll& source, vll& dist, vector<bool>& visited, ll& limit_day) {
    ll n = source.size();
    queue<ll> qu;

    for (size_t i = 0; i < n; i++) {
        qu.push(source[i]);
        visited[source[i]] = true;
    }

    multisourceBFS(AL, qu, dist, visited, source, limit_day);

    // print out the number of nodes in the day_array list
    // for (size_t day = 1; day < limit_day + 1; day++) {
    //     sort(day_array[day].begin(), day_array[day].end());
    //     printVector(day_array[day]);
    // }
    // cout << '\n';

    sort(source.begin(), source.end());
    for (auto& k : source) {
        cout << k << ' ';
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, d, c; cin >> n >> d >> c;
    vll infected;
    vector<bool> visited(n + 1, false); // keep track if visited or not, account for non-zero indexing
    vll dist(n + 1, 0); // for keeping track of distance between source
    for (ll i = 0; i < c; i++) {
        ll x; cin >> x;
        infected.push_back(x); // account for zero indexing
    }

    vector<tuple<ll, ll, ll>> timings;
    for (size_t i = 1; i < n + 1; i++) {
        ll s, t; cin >> s >> t;
        timings.push_back(make_tuple(s, START, i));
        timings.push_back(make_tuple(t, END, i));
    }
    sort(timings.begin(), timings.end());
    // for (auto& [k, time, v] : timings) {
    //     cout << "<" << k << ", " << time << ", " << v << ">";
    // }

    unordered_set<ll> us;
    vector<vll> AL(n + 1);
    for (auto& [t, time, u] : timings) {
        // erase duplicated index as we have reached the end, continue to so that we can move onto next index
        // thus, we will know when we have met the first end time
        // anything in between the start time taken, until we found the nearest end time, is connected
        // think of it as a sorted stack
        // for example, as its sorted, we will know the closest start to end times
        // anything inbetween those start times are overlapping or equal, and thus are connected
        // once we reach an end point, we move on to the next start point
        if (time == END) { us.erase(u); continue; } // by erasing we continue to the next node
        for (auto& v : us) {
            AL[u].push_back(v);
            AL[v].push_back(u);
        }
        us.insert(u);
    }

    // printVectorOfVectors(AL);

    nearestToMaxNode(AL, infected, dist, visited, d);

    return 0;
}
