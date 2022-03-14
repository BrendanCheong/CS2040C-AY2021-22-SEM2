#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

// custom long long int hash function
struct ll_hash {
    static ll splitmix64(ll x) {
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
        for (auto& c : s) { // long input strings are not ideal
            h ^= (h << 5) + (h >> 2) + (c);
        }
        return h;
    }
};

// custom char hash function
struct char_hash {
    size_t operator()(const char& c) const {
        static const ll FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return FIXED_RANDOM;
    }
};

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    gp_hash_table<ll, ll, ll_hash> HashTable;
    gp_hash_table<string, string, string_hash> HashString;
    HashTable[1] = 10;
    HashTable[2] = 20;
    cout << HashTable[2] << endl;
    HashString["apple"] = "int";
    HashString["green"] = "trees";
    cout << HashString["apple"] << endl;
    map<ll, string> avl;
    avl[15] = "apple";
    avl[23] = "pear";
    avl[6] = "kiwi";
    avl[71] = "lime";
    avl[50] = "orange";
    avl[4] = "lemon";
    avl[7] = "durian";
    avl[5] = "banana";
    auto it = avl.upper_bound(20); // 23 pear
    auto it2 = avl.lower_bound(20); // 15 apple
    it2--;
    cout << it->first << " " << it->second << endl;
    cout << it2->first << " " << it2->second << endl;
    // a HashTable where K, V: identifier, {int-> number of brackets, List[string] -> list of types

    return 0;
}