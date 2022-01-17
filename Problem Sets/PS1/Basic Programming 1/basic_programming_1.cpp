#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
using ll = long long;

ll case1(vector<ll> arr)
{
    return 7;
}

string case2(vector<ll> arr)
{
    ll num1 = arr[0];
    ll num2 = arr[1];

    if (num1 > num2)
    {
        return "Bigger";
    }
    else if (num1 == num2)
    {
        return "Equal";
    }
    else
    {
        return "Smaller";
    }
}

ll case3(vector<ll> arr)
{
    vector<ll> median{arr[0], arr[1], arr[2]};

    // sort the vector
    sort(median.begin(), median.end());

    return median[1];
}

ll case4(vector<ll> arr)
{
    ll accumulator = 0; // has to accumulate into a long long not an int by default
    return accumulate(arr.begin(), arr.end(), accumulator);
}

ll case5(vector<ll> arr, ll size)
{
    ll evenSum = 0;
    for (auto &i : arr)
    {
        if (i % 2 == 0)
        {
            evenSum += i;
        }
    }
    return evenSum;
}

string case6(vector<ll> arr, ll size)
{
    string result = "";
    for (ll i = 0; i < size; ++i)
    {
        result += (char)('a' + arr[i] % 26);
    }

    return result;
}

string case7(vector<ll> arr, ll size)
{
    ll index = arr[0];
    unordered_set<ll> llSet;

    // initialise the set
    llSet.insert(index);

    while (index < size)
    {
        // if the current index i is index N-1, push “Done” and stop;
        if (index == size - 1)
        {
            return "Done";
        }
        index = arr[index];

        // if element is already in the set, sound off as Cyclic
        // else, add element llo set
        if (llSet.find(index) == llSet.end())
        {
            llSet.insert(index);
        }
        else
        {
            return "Cyclic";
        }
    }

    return "Out";
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll size = 0;
    ll t = 0;

    cin >> size;
    cin >> t;

    vector<ll> arr(size, 0);

    for (ll i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    switch (t)
    {
    case (2):
        cout << case2(arr);
        break;
    case (3):
        cout << case3(arr);
        break;
    case (4):
        cout << case4(arr);
        break;
    case (5):
        cout << case5(arr, size);
        break;
    case (6):
        cout << case6(arr, size);
        break;
    case (7):
        cout << case7(arr, size);
        break;
    default:
        cout << case1(arr);
        break;
    }

    return 0;
}