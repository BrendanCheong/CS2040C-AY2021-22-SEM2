/**
 * Matric: A0217988E
 * Name: Brendan Cheong Ern Jie
 * Lab: 10
 * TA: Fidella Widjojo
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> accumulateVector(ll N) { // O(N)
    vector<ll> result;
    int num;
    for (ll i = 0; i < N; ++i) {
        cin >> num;
        result.push_back(num);
    }
    return result;
}

void case4(vector<ll> arr, ll N) {
    sort(arr.begin(), arr.end()); // O(N Log N)
    if (N % 2 != 0) { // O(1)
        // odd
        cout << arr[N / 2];
    }
    else {
        ll first = arr[(N / 2) - 1];
        ll second = arr[N / 2];
        cout << first << ' ' << second;
    }
}

ll case3(vector<ll> arr, ll N) {
    map<ll, ll> dict;

    for (size_t i = 0; i < N; i++)
    {
        if (dict.count(arr[i])) {
            ++dict[arr[i]];
            ll answer = dict[arr[i]];
            if (answer > (N / 2)) {
                return arr[i];
            }
        }
        else {
            dict[arr[i]] = 1;
        }
    }

    return -1;
}

string case2(vector<ll> arr) {
    map<ll, ll> dict;
    for (auto& number : arr) {
        if (!dict.count(number)) {
            dict[number] = 10;
        }
        else {
            return "Contains duplicate";
        }
    }
    return "Unique";
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, t, num = 0;
    cin >> N >> t;
    vector<ll> arr;


    if (t == 2) {
        cout << case2(accumulateVector(N)) << endl;
    }
    else if (t == 3) {
        cout << case3(accumulateVector(N), N) << endl;
    }
    else if (t == 4) {
        case4(accumulateVector(N), N);
    }
    else if (t == 5) {
        for (size_t i = 0; i < N; ++i) {
            cin >> num;
            if (!(num < 100) && !(num > 999)) {
                arr.push_back(num);
            }
        }
        sort(arr.begin(), arr.end()); // O(N Log N)

        for (ll i = 0; i < arr.size() - 1; ++i) { // O(N)
            cout << arr[i] << ' ';
        }
        cout << arr[arr.size() - 1] << endl;
    }
    else {
        unordered_set<ll> llset;
        arr = accumulateVector(N);
        bool truth = false;

        for (ll i = 0; i < N; ++i)
        {
            ll complement = 7777 - arr[i];

            if (llset.find(complement) == llset.end()) {
                llset.insert(arr[i]);
            }
            else {
                truth = true;
                break;
            }
        }
        truth
            ? cout << "Yes"
            : cout << "No";
    }

    return 0;
}