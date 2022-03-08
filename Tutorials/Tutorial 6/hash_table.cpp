#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
class hash_table { // this is an attempt to emulate unordered_map<string, int> ht_stl;
// the 'easiest' and most robust Hash Table is actually the one with Separate Chaining collision resolution technique
private:
    // interesting (new) technique, we can create an array (or vector) of another STLs, here we have a vector of std::list (of pair of (string, int))
    vector<list<pair<T1, T2>>> underlying_table;
    int total;
    int M = 997; // M = table size is a prime number, generally make load factor alpha = N/M < 7 (just a small number) where N is the maximum number of keys that you will likely need for your application

    // from https://visualgo.net/en/hashtable?slide=4-7
    int hash_function(string v) { // assumption 1: v uses ['A'..'Z'] only (be careful if this assumption is not true); assumption 2: v is a short string
        int sum = 0;
        for (auto& c : v) { // for each character c in v
            sum = ((sum * 26) % M + (c - 'A' + 1)) % M; // M is table size
        }
        return sum;
    }

public:
    hash_table() { // O(M)
        underlying_table.assign(M, list<pair<T1, T2>>()); // create M empty std::lists
        total = 0;
    }

    hash_table(int _M) : M(_M) { // O(M), this time we can control the hash-table size
        underlying_table.assign(M, list<pair<T1, T2>>()); // create M empty std::lists
        total = 0;
    }

    ~hash_table() { // O(M)
        for (int i = 0; i < M; ++i)
            underlying_table[i].clear();
    }

    void insert(pair<T1, T2> key_value) { // O(1+alpha), to emulate ht_stl[key] = value or ht_stl.insert({key, value})
        auto& [key, value] = key_value; // decompose into key and value
        bool contains_key = false;
        for (auto& [k, v] : underlying_table[hash_function(key)])
            if (k == key) { // if there is an existing key
                contains_key = true;
                v = value; // update the satellite data, notice that we use pass by reference '&' above
            }

        if (!contains_key) { // no previous key before
            underlying_table[hash_function(key)].emplace_back(key, value); // just append at the back
            ++total;
        }
    }

    T2 find(T1 key) { // O(1+alpha), to emulate ht_stl[key] or ht_stl.find(key)
        for (auto& [k, v] : underlying_table[hash_function(key)]) // O(k), k is the length of this list, but with careful setup, k can be O(1)
            if (k == key) // if there is an existing key
                return v; // return this satellite data

            // if there is no previous key before (return v above is never executed)
        return -1; // we return a special symbol to say such key does not exist
    }

    void erase(T1 key) { // O(1+alpha), to emulate ht_stl.erase(key)
        auto& row = underlying_table[hash_function(key)]; // get the reference of the row, notice that we use pass by reference '&' (VERY IMPORTANT)

        for (auto it = row.begin(); it != row.end(); ++it)
            if (it->first == key) { // if there is an existing key
                row.erase(it); // erase this (key, value) pair from this vector
                --total;
                break; // do not do anything else
            }

        // we do nothing if key is not actually found
    }

    bool empty() {
        return total == 0;
    }
};

int main() {
    cout << "Our own Hash Table with Separate Chaining collision resolution technique\n";
    hash_table<string, int> ht(13); // control the load factor upfront for a better performance (memory vs performance trade-off)
    cout << ht.empty() << '\n'; // should be 1/true

    ht.insert({ "STEVEN", 77 });
    cout << ht.empty() << '\n'; // should be 0/false

    ht.insert({ "STEVEN", 38 }); // will update instead of creating a new one
    ht.insert({ "GRACE", 37 });
    ht.insert({ "JANE", 9 });
    ht.insert({ "JOSHUA", 6 });
    ht.insert({ "JEMIMAH", 3 });
    cout << ht.find("STEVEN") << '\n'; // should be 38 (not 77, it has been overwritten)
    cout << ht.find("GRACE") << '\n'; // should be 37
    cout << ht.find("STRANGER") << '\n'; // should be -1 (does not exist)

    ht.erase("STEVEN");
    cout << ht.find("STEVEN") << '\n'; // should be -1 now (has just been deleted)
    cout << ht.find("GRACE") << '\n'; // should remain 37
    cout << ht.find("JANE") << '\n'; // should be 9

    ht.erase("JANE");
    cout << ht.find("JANE") << '\n'; // should be -1 now (has just been deleted)

    cout << "C++ STL version\n";
    unordered_map<string, int> ht_stl(13); // control the load factor upfront for a better performance (memory vs performance trade-off)
    cout << ht_stl.empty() << '\n'; // should be 1/true

    ht_stl["STEVEN"] = 77;
    cout << ht_stl.empty() << '\n'; // should be 0/false

    ht_stl["STEVEN"] = 38; // will update instead of creating a new one
    ht_stl.insert({ "GRACE", 37 }); // the longer route, just use the '[]' operator instead
    ht_stl["JANE"] = 9;
    ht_stl["JOSHUA"] = 6;
    ht_stl["JEMIMAH"] = 3;
    cout << ht_stl["STEVEN"] << '\n'; // should be 38 (not 77, it has been overwritten)
    cout << ht_stl["GRACE"] << '\n'; // should be 37
    cout << (ht_stl.find("STRANGER") == ht_stl.end() ? -1 : 1) << '\n'; // should be -1 ("STRANGER" does not exist)

    ht_stl.erase("STEVEN");
    cout << (ht_stl.find("STEVEN") == ht_stl.end() ? -1 : 1) << '\n'; // should be -1 (has just been deleted)
    cout << ht_stl["GRACE"] << '\n'; // should remain 37
    cout << ht_stl["JANE"] << '\n'; // should be 7

    ht_stl.erase("JANE");
    cout << (ht_stl.find("JANE") == ht_stl.end() ? -1 : 1) << '\n'; // should be -1 now (has just been deleted)

    return 0;
}