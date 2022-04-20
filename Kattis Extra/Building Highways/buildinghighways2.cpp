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
typedef tuple<ll, ll, ll> lll;
#define INF 10e15
template <class T> using binary_tree = tree<T, null_type, logical_and<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n; ll sum = 0; ll minimum = INF; cin >> n; for (size_t i = 0; i < n; i++) { ll d; cin >> d;  sum += d; minimum = min(d, minimum); }
    cout << (minimum * (n - 2)) + sum << endl;

    /**
     * Pseudo Code:
     * Since its a complete graph, the MST is will be the tree where the LOWEST WEIGHTED NODE is the root
     * that its connected to all other vertices from the outgoing edges from that lowest weighted root
     * This works with duplicates
     * So just sort to find the lowest value root.
     * Given that the MST is V - 1 edges, multiply by V - 2, then add the sum of all weighted nodes
    */

    return 0;
}