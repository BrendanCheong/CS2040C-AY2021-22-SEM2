/**
 * Matric: A0217988E
 * Name: Brendan Cheong Ern Jie
 * Lab: 10
 * TA: Fidella Widjojo
*/
#include<bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long int;
template <class T> using binary_tree = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; // allows duplicates, sorted ascending

template<class T>
void printBinaryTree(binary_tree<T>& bt, ll N) {
    cout << '[';
    for (size_t i = 0; i < N; i++) {
        cout << *bt.find_by_order(i);
        (i == (N - 1)) ? cout << ']' : cout << ", ";
    }
    cout << '\n';
}

ll solve(ll count) {
    binary_tree<ll> pq_min;
    ll ans = 0;
    for (size_t i = 0; i < count; i++) { // O(N)
        ll x; cin >> x;
        pq_min.insert(x); // O(log N)
        ll size = pq_min.size();
        if (size % 2 != 0) {
            ll median = *pq_min.find_by_order(size / 2); // O(log N)
            ans += median;
        }
        else {
            ll median = *pq_min.find_by_order((size / 2) - 1); // O(log N)
            ll median_next = *pq_min.find_by_order(size / 2); // O(log N)
            // cout << "numbers are: " << median << ", " << median_next << '\n';
            ans += (median + median_next) / 2;
        }
    }
    // printBinaryTree(pq_min, count);
    return ans; // O(N log N)
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T = 0;

    cin >> T;
    for (size_t i = 0; i < T; i++) { // O(T)
        ll size; cin >> size;
        cout << solve(size) << '\n'; // O(N log N)
    }
    return 0; // O(TN log N)
}