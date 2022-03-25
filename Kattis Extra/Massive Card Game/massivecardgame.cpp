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
template <class T> using binary_tree = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min

// print a set<ll>
template <class T>
void printSet(multiset<T>& st) {
    ll N = st.size();
    cout << '[';
    for (auto& k : st) {
        cout << k;
        (--N) ? cout << ", " : cout << ']';
    }
    cout << '\n';
}

// print vector
template <class T>
void printVector(vector<T>& v) {
    ll N = v.size();
    cout << '[';
    for (auto& k : v) {
        cout << k;
        (--N) ? cout << ", " : cout << ']';
    }
    cout << '\n';
}

void solve(vector<ll>& arr) {
    ll N; cin >> N;
    while (N--) {
        ll a, b; cin >> a >> b;
        auto pos_low = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
        auto pos_high = upper_bound(arr.begin(), arr.end(), b) - arr.begin();
        cout << (pos_high - pos_low) << '\n';
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N; cin >> N;
    binary_tree<ll> bt;
    vector<ll> arr;
    multiset<ll> stl;
    while (N--) {
        ll input; cin >> input;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end()); // O(N log N)
    // printVector(arr);
    solve(arr);

    return 0;
}
