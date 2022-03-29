// PL4_Z0R04RK
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long int;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define INF 0x3f3f3f3f
template <class T> using binary_tree = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
    ll n, k; cin >> n >> k;
    ll input;
    vll arr;
    unordered_set<ll> types;
    while (cin >> input) {
        arr.push_back(input);
        types.insert(input);
    }
    ll max_count = -1;
    // vll heights;
    std::priority_queue<ll, vll, less<ll>> pq;
    sort(arr.begin(), arr.end());
    for (auto& k : types) {
        auto pos_low = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
        auto pos_high = upper_bound(arr.begin(), arr.end(), k) - arr.begin();
        ll count = pos_high - pos_low;
        max_count = max(max_count, count);
        pq.push(count);
    }
    // sort(heights.begin(), heights.end());

    if (k == 0)
        cout << max_count << '\n';
    else {
        // if the last element is bigger than the element behind it, decrease the count of the last element until the last element and the element behind it are equal
        // if equal, then do the same for the element behind it, decrease until equal
        // and so on
        // do this for k counts

        // RIP: I should've use PQ_max or binary_tree with greater<T> comparator
        while (k--) {
            ll max = pq.top();
            ll new_max = max - 1;
            pq.pop();
            pq.push(new_max);
        }

        cout << pq.top() << '\n';
    }
    // printVector(heights);

    return 0;
}
