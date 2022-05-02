#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long int;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define INF 0x3f3f3f3f

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

void quadraticProbe(ll num, ll m) {
    // m is table size, usually its 13
    ll T = 0;
    for (size_t i = 0; i < m; i++) {
        if (i == 0) {
            T = num % m;
            cout << T << " is for first hash\n";
            continue;
        }
        cout << (T + i * i) % m << " is for #" << i + 1 << " hash\n";
    }
}

void linearProbe(ll num, ll m) {
    ll T = 0;
    for (size_t i = 0; i < m; i++) {
        if (i == 0) {
            T = num % m;
            cout << T << " is for first hash\n";
            continue;
        }
        cout << (T + i * 1) % m << " is for #" << i + 1 << " hash\n";
    }
}

void doubleProbing(ll num, ll m, ll second_m, ll reduction) {
    ll T = 0;
    ll K = reduction - (num % second_m);
    for (size_t i = 0; i < m; i++) {
        if (i == 0) {
            T = num % m;
            cout << T << " is for first hash\n";
            continue;
        }
        // assume its 11 - k % 11
        cout << (T + i * K) % m << " is for #" << i + 1 << " hash\n";
    }
}

void LP(vll& hashTable, vll& keys, ll m) {
    for (size_t i = 0; i < keys.size(); i++) {
        ll hash = keys[i] % m;
        if (hashTable[hash] == 999) {
            hashTable[hash] = keys[i];
        }
        else {
            ll T = keys[i] % m;
            int j = 1;
            while (hashTable[hash] != 999) {
                hash = (T + j * 1) % m;
                ++j;
            }
            hashTable[hash] = keys[i];
        }
    }
}

void QP(vll& hashTable, vll& keys, ll m) {
    for (size_t i = 0; i < keys.size(); i++) {
        ll hash = keys[i] % m;
        if (hashTable[hash] == 999) {
            hashTable[hash] = keys[i];
        }
        else {
            ll T = keys[i] % m;
            int j = 1;
            while (hashTable[hash] != 999) {
                hash = (T + j * j) % m;
                ++j;
            }
            hashTable[hash] = keys[i];
        }
    }
}

void DH(vll& hashTable, vll& keys, ll m, ll second_m, ll reduction) {
    for (size_t i = 0; i < keys.size(); i++) {
        ll hash = keys[i] % m;
        if (hashTable[hash] == 999) {
            hashTable[hash] = keys[i];
        }
        else {
            ll T = keys[i] % m;
            ll K = keys[i] % second_m;
            int j = 1;
            while (hashTable[hash] != 999) {
                hash = (T + j * (reduction - K)) % m;
                ++j;
            }
            hashTable[hash] = keys[i];
        }
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //? variables I must input
    const ll table_size = 11;
    const ll reduction = 11; // reduction for double hashing
    const ll second_hash = 11; // second m to hash for double hashing

    //? for the questions asking what the sequene of insertions are, will tell you which index to put the number
    // quadraticProbe(59, table_size);
    linearProbe(45, table_size);
    // doubleProbing(75, table_size, second_hash, reduction);


    //? for the keys question, will actually hash the keys and insert into "hashtable" or sorts
    vector<ll> hashTable(table_size, 999);
    vector<ll> keys = { 41, 5, 40, 30, 19 };

    LP(hashTable, keys, table_size);
    // QP(hashTable, keys, table_size);
    // DH(hashTable, keys, table_size, second_hash, reduction);

    printVector(hashTable);

    return 0;
}
