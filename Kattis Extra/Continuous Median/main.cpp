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

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T = 0;

    cin >> T;

    for (size_t i = 0; i < T; ++i) {
        ll N = 0;
        cin >> N;
        vector<ll> arr;
        ll ans;

        for (size_t j = 0; j < N; ++j) {
            ll number = 0;
            cin >> number;
            arr.push_back(number);

            ll sizeOfArr = arr.size();

            if (sizeOfArr == 1) {
                ans += number;
                break;
            }
            else if (sizeOfArr == 2) {
                ans += arr[0] + arr[1];
            }

            if (sizeOfArr % 2 != 0) {
                ans += arr[sizeOfArr / 2];
            }
            else {
                int first = arr[(sizeOfArr / 2) - 1];
                int second = arr[sizeOfArr / 2];
                ans += (first + second) / 2;
            }
        }

        cout << ans << '\n';

    }


    return 0;
}