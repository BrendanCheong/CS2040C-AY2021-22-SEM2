#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long int;
template <class T> using binary_tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //!NOTE: make use of pair<ll,ll> to create unique elements with an index on the right!
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min

ll convertNum(string s) {
    char* p;
    ll converted = strtol(s.c_str(), &p, 10);
    if (*p)
        return -1;
    else
        return converted;
}

// print a binary_tree
template <class T>
void printBinaryTree(binary_tree<T>& bt) {
    ll N = bt.size();
    cout << '[';
    for (size_t i = 0; i < N; i++) {
        auto ele = *bt.find_by_order(i);
        cout << "<" << ele.first << ", " << ele.second << ">";
        (i == (N - 1)) ? cout << ']' : cout << ", ";
    }
    cout << '\n';
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string holder;
    binary_tree<pair<ll, ll>> cookie_tree;
    ll ele = 0;
    while (cin >> holder) {
        ll num = convertNum(holder);
        if (num != -1) {
            pair<ll, ll> pll = { num, ele };
            cookie_tree.insert(pll);
            ele++;
        }
        else {
            ll size = cookie_tree.size();
            // printBinaryTree(cookie_tree);
            if (size % 2 == 0) {
                auto index = size / 2;
                pair<ll, ll> median_pair = *cookie_tree.find_by_order(index);
                cout << median_pair.first << '\n';
                cookie_tree.erase(median_pair); // !NOTE: this only works on less<> as the binary_tree is unique!
            }
            else {
                auto index = ((size + 1) / 2) - 1;
                pair<ll, ll> median_pair = *cookie_tree.find_by_order(index);
                cout << median_pair.first << '\n';
                cookie_tree.erase(median_pair);
            }
        }
    }

    return 0;
}
