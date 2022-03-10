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

template <class T>
void printBinaryTree(binary_tree<T>& tree) {
    for (size_t i = 0; i < tree.size(); i++) {
        cout << *tree.find_by_order(i) << ' ';
    }
}
template <class T>
void solve(map<T, binary_tree<T>>& breakfast, ll N) {
    string key, food;
    for (size_t i = 0; i < N; i++) {
        cin >> key;
        while (cin.peek() != '\n') {
            cin >> food;
            breakfast[food].insert(key); // pbds auto sorts accordingly
        }
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N;
    map<string, binary_tree<string>> breakfast; // use map to sort keys by alphabetically order
    while (cin >> N && N != 0) {
        breakfast.clear();
        solve(breakfast, N);

        for (auto& [k, v] : breakfast) {
            cout << k << ' ';
            printBinaryTree(v);
            cout << '\n';
        }
    }

    return 0;
}