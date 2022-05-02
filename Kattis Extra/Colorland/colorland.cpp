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
template <class T> using binary_tree = tree<T, null_type, logical_and<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min

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

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n; cin >> n;
    ll colorboard[n + 1]; // your array in numbers
    unordered_map<string, ll> colors = {
        {"Blue", 1},
        {"Orange", 2},
        {"Pink", 3},
        {"Green", 4},
        {"Red", 5},
        {"Yellow", 6}
    };

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        colorboard[i + 1] = colors[s];
    }

    ll start = 0, best = 0, ans = 0;
    while (start < n) {
        for (ll i = 1; i <= 6; ++i) {
            ll it = find(colorboard + start + 1, colorboard + n + 1, i) - colorboard;
            if (it != n + 1)
                best = max(it, best);
        }

        start = best;
        ans++;
        // cout << start << '\n';
    }
    cout << ans << '\n';

    /**
    * Pseudo Code:
    * 0) For all colors, do this:
    * 1) Basically find the furthest first unique element from the start of 0 and take the index as k.
    * Let k + 1 become your next start point.
    * 2) if the color is not in the array, carry on with the next color
    * 3) After finding a valid k, store it in an ans array. Among this array we want to find the highest k.
    * 4) Algo should be in O(n) time
    * 5) Do this until we reach a point where k is out of bounds, or where k + 1 > n
    * 6) The number of times we run this algo, or the number of cycles is our answer
    */
    return 0;
}
