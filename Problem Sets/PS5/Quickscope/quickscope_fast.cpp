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

// custom long long hash
struct ll_hash {
    static ll splitmix64(ll x) { // O(1) hash
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(ll x) const {
        static const ll FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// custom string hash function
struct string_hash {
    size_t operator()(const string& s) const {
        static const ll FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        size_t h = FIXED_RANDOM;
        for (auto& c : s) { // long input strings are not ideal but max 6 characters is ok O(6)
            h ^= (h << 5) + (h >> 2) + (c);
        }
        return h;
    }
};

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N; cin >> N;
    ll depth = 0;
    map<ll, gp_hash_table<string, string, string_hash>> block;
    gp_hash_table<string, set<ll>, string_hash> HashTable;
    string var, type;
    while (N--) {
        string cmd; cin >> cmd;
        switch (cmd[0]) {
        case('{'):
            ++depth;
            break;
        case('}'):
            if (block.find(depth) != block.end()) {
                for (auto& [k, v] : block[depth])
                    HashTable[k].erase(depth);
                block.erase(depth); // frequent deletion, might be better if I use AVL, we'll see
            }
            --depth;
            break;
        case('T'):
            cin >> var;
            if (HashTable.find(var) != HashTable.end()) {
                ll new_depth;
                auto it = HashTable[var].lower_bound(depth);
                if (HashTable[var].count(depth))
                    new_depth = depth;
                else if (it != HashTable[var].begin()) {
                    it--;
                    new_depth = *it;
                }
                else {
                    cout << "UNDECLARED" << '\n';
                }
                if (block.find(new_depth) != block.end() && block[new_depth].find(var) != block[new_depth].end())
                    cout << block[new_depth][var] << '\n';
            }
            else
                cout << "UNDECLARED" << '\n';
            break;
        case('D'):
            cin >> var >> type;
            if (block[depth].find(var) == block[depth].end())
                block[depth][var] = type;
            else {
                cout << "MULTIPLE DECLARATION" << '\n';
                return 0;
            }
            HashTable[var].insert(depth);
            break;
        }
    }

    return 0;
}
