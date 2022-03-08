#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long int;
template <class T> using binary_tree = tree<T, null_type, logical_and<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min

void removeDupWord(string str, unordered_set<string>& set) {
    string word = "";
    for (auto x : str) {
        if (x == ' ') {
            if (set.find(word) == set.end())
                cout << word << ' ';
            word = "";
        }
        else
            word = word + x;

    }

    if (set.find(word) == set.end())
        cout << word << '\n';
    else
        cout << '\n';
}

void solve(string line) {
    unordered_set<string> set;
    while (true) {
        string animal, goes, sound; cin >> animal;
        if (animal == "what")
            break;
        cin >> goes >> sound;
        set.insert(sound);
    }
    removeDupWord(line, set);
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        string line;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, line);
        solve(line);
    }

    return 0;
}