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
    ll N; cin >> N;

    ll start = -1;
    vector<list<string>> words; words.assign(N + 1, list<string>());
    for (size_t i = 1; i < N + 1; i++) {
        string word; cin >> word;
        words[i].push_back(word);
    }

    if (N == 1) { // for that damn edge case of N = 1
        for (auto& fuck : words[1]) {
            cout << fuck;
        }
        return 0;
    }

    N = N - 1;
    while (N--) {
        ll join, target; cin >> join >> target;
        words[join].splice(words[join].end(), words[target]);
        if (N == 0) {
            start = join;
        }
    }

    for (auto& i : words[start]) {
        cout << i;
    }

    return 0;
}
