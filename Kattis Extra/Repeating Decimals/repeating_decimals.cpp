#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ld = long double;
using ull = unsigned long long int;
template <class T> using binary_tree = tree<T, null_type, logical_and<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    const ll limit = 100;
    ll a;
    while (cin >> a) {
        ll b, c; cin >> b >> c;
        cout << "0.";
        for (size_t i = 0; i < c; i++) {
            if (a < b)
                a = a * 10;
            cout << a / b;
            a %= b;
        }
        cout << '\n';
    }

    return 0;
}
