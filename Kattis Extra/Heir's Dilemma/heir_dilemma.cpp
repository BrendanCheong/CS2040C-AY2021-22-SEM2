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

    return 0;

    ll start, end, count = 0;
    cin >> start >> end;

    while (start <= end) {

        ll arr[10] = {};
        ll first, second, third, fourth, fifth, sixth;
        first = start / 100000;
        second = start / 10000 % 10;
        third = start / 1000 % 10;
        fourth = start / 100 % 10;
        fifth = start / 10 % 10;
        sixth = start % 10;
        arr[first] += 1;
        arr[second] += 1;
        arr[third] += 1;
        arr[fourth] += 1;
        arr[fifth] += 1;
        arr[sixth] += 1;
        bool ok = arr[0] > 0 ? false : true;
        for (size_t i = 0; i < 10; i++)
        {
            if (arr[i] > 1) {
                ok = false;
            }
        }
        if (ok && start % first == 0 && start % second == 0 && start % third == 0 && start % fourth == 0 && start % fifth == 0 && start % sixth == 0) {
            count++;
        }
        start++;
    }

    cout << count;
}