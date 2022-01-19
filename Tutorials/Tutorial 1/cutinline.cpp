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
    ll people, actions = 0;
    string element;
    vector<string> arr;

    cin >> people;
    for (size_t i = 0; i < people; ++i) // O(N)
    {
        cin >> element;
        arr.push_back(element);
    }
    cin >> actions;

    // O(N^2) solution because I didn't use a hash map lmao.
    while (--actions + 1) { // O(N)
        string action, ele1, ele2;
        cin >> action;
        if (action == "cut") { // O(1)
            cin >> ele1 >> ele2;
            auto ret = find(arr.begin(), arr.end(), ele2);
            int index = ret - arr.begin(); // O(N^2)
            arr.insert(arr.begin() + index, ele1);
        }
        else {
            cin >> ele1;
            auto ret = find(arr.begin(), arr.end(), ele1);
            int index = ret - arr.begin();
            arr.erase(arr.begin() + index);
        }
    }

    for (auto& i : arr) { // O(N)
        cout << i << '\n';
    }

    return 0;
}
