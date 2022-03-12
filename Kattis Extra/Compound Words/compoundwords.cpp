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
template <class T> using binary_tree = tree<T, null_type, logical_and<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string word;
    vector<string> arr;
    set<string> compounded;

    while (cin >> word) {
        for (auto& w : arr) {
            compounded.insert(w + word);
            compounded.insert(word + w);
        }
        arr.push_back(word);
    }

    // print out compounded
    for (auto& w : compounded) {
        cout << w << '\n';
    }

    return 0;
}