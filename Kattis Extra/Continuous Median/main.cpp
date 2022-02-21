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

void printVec(vector<ll>& arr) {
    cout << '[';
    for (auto& i : arr) {
        cout << i << ", ";
    }
    cout << ']' << endl;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T = 0;

    cin >> T;

    for (size_t i = 0; i < T; ++i) { // O(T)
        ll N = 0; cin >> N;
        vector<ll> arr;
        ll ans = 0;
        ll starter = 0;
        for (size_t i = 0; i < N; i++) { //O(N)
            ll num; cin >> num;
            arr.push_back(num);
            sort(arr.begin(), arr.end()); //O(N log N)
            ll size = arr.size();
            if (size % 2 == 0) {
                ll first = arr[starter];
                ll second = arr[starter + 1];
                //cout << "even: " << first << ", " << second << endl;
                // cout << starter << ' ' << starter + 1 << endl;
                // printVec(arr);
                ans += (first + second) / 2;
                ++starter;
            }
            else {
                //cout << "odd: " << arr[starter] << endl;
                // cout << starter << endl;
                // printVec(arr);
                ans += arr[starter];
            }
        }
        cout << ans << '\n';
        starter = 0;
    }

    return 0;
}