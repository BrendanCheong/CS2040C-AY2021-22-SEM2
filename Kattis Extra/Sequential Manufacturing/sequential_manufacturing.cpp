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
    ll N, P; cin >> N >> P;
    ll maximum = 0;
    ll sum = 0;
    while (N--) {
        ll input; cin >> input;
        maximum = max(maximum, input);
        sum += input;
    }

    cout << sum + ((P - 1) * maximum) << endl;

    return 0;
}