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
    // Obviously we use a DLL for this, similarly this qns relies on a "Circular LL"
    // I need to keep track of all the iterators of the people in the conga line
    // if 'C' is cast, then I will insert behind the partner based on the iterator
    // but how do I update the iterator? if A partner B, then B A, how do I update A iterator
    // Ans: each dancer knows their partners iterator
    // after inserting, update the dancer's partner iterator
    unordered_map<string, list<string>::iterator> track;
    string p1, p2;
    for (size_t i = 0; i < n; i++) {
        cin >> p1 >> p2;
        conga.push_back(p1);
        partners[p1] = p2;
        track[p2] = --conga.end(); // each dancer knows the partners iterator
        conga.push_back(p2);
        partners[p2] = p1;
        track[p1] = --conga.end(); // same here, have to wait until we push_back to list
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
        case('R'): // linear O(1) move since the input is an iterator
            auto original_it = it;
            string element = *original_it;
            ++it;
            if (it == conga.end()) it = conga.begin();
            conga.erase(original_it); // O(1)
            conga.push_back(element);
            break;
        }
        if (input == 'C') {
            auto original_it = it;
            string current_dancer = *original_it;
            ++it;
            if (it == conga.end()) it = conga.begin();
            // insert at my partners given original_it
            conga.erase(original_it); // O(1)
            auto partner_it = track[current_dancer];
            auto new_partner_it = conga.insert(next(partner_it), current_dancer);
            // update my dancer's partner iterator with the new inserted iterator 
            // that belongs to the dancer
            track[partners[current_dancer]] = new_partner_it;
        }
    }
    cout << '\n';
    for (auto& k : conga) {
        cout << k << '\n';
    }

    return 0;
}
