/**
 * Matric: A0217988E
 * Name: Brendan Cheong Ern Jie
 * Lab: 10
 * TA: Fidella Widjojo
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long int;

void printMap(unordered_map<string, int>& map) {
    // print out the map
    for (auto it = map.begin(); it != map.end(); it++) {
        cout << "{" << it->first << ", " << it->second << "}" << endl;
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // create a map of each possible possibilities of the given name string
    // so thats 10N time since max 10 characters
    // then iterate through B in N time, O(N) time
    // for each letter, indexing map in O(1) time
    // so total should be O(10N + N) = O(11N)

    ll A, B;
    string names, nicknames;
    unordered_map<string, int> name_map;
    cin >> A;
    for (size_t i = 0; i < A; i++) { // O(A)
        cin >> names;
        for (size_t j = 0; j < names.size(); j++) { // O(10) max
            name_map[names.substr(0, j + 1)]++; // O(1) time since hash table
        }
    }

    cin >> B;
    for (size_t i = 0; i < B; i++) { // O(B)
        cin >> nicknames;
        cout << name_map[nicknames] << endl; // O(1) time since hash table
    }

    //total time complexity: O(10A + B) 

    return 0;
}