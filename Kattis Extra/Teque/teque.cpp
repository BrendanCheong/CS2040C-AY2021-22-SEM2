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
    ull N, x;
    string S;
    deque<ull> dq1, dq2;
    map<string, ull> dct = {
        {"push_back", 1},
        {"push_front", 2},
        {"push_middle", 3},
        {"get", 4}
    };

    cin >> N;
    for (size_t i = 0; i < N; ++i) {
        cin >> S >> x;
        ull size1 = dq1.size(); ull size2 = dq2.size();
        switch (dct[S]) {
        default:
            break;
        }
    }


    return 0;
}