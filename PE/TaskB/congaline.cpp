// PL4_Z0R04RK
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long int;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define INF 0x3f3f3f3f
template <class T> using binary_tree = tree<T, null_type, logical_and<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
    ll n, q; cin >> n >> q;
    list<string> conga;
    unordered_map<string, string> partners;
    string p1, p2;
    for (size_t i = 0; i < n; i++) {
        cin >> p1 >> p2;
        conga.push_back(p1);
        conga.push_back(p2);
        partners[p1] = p2;
        partners[p2] = p1;
    }
    char input;
    auto it = conga.begin();
    while (cin >> input) {
        switch (input) {
        case('P'):
            cout << partners[*it] << '\n';
            break;
        case ('B'):
            ++it;
            break;
        case('F'):
            --it;
            break;
        case('R'): // gg linear O(n) move
            auto original_it = it;
            string element = *original_it;
            ++it;
            if (it == conga.end()) it = conga.begin();
            conga.erase(original_it); // O(n)
            conga.push_back(element);
            break;
        }
    }
    cout << '\n';
    for (auto& k : conga) {
        cout << k << '\n';
    }

    // unordered_set<string> players;
    // for (auto& k : conga) {
    //     players.insert(k);
    //     if (players.count(partners[k])) { // if I can find my partner!
    //         cout << partners[k] << '\n';
    //         cout << k << '\n';
    //         players.erase(k);
    //         players.erase(partners[k]);
    //     }
    // }

    return 0;
}
