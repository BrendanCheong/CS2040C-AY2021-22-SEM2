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
    ll output = 0;
    for (auto &i : arr)
    {
        output += i;
    }
    return output;
}

ll case5(vector<ll> arr)
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

string case6(vector<ll> arr)
{
    string result = "";
    ll number = 0;
    ll letter = 0;
    map<ll, char> alphabet = {
        {0, 'a'},
        {1, 'b'},
        {2, 'c'},
        {3, 'd'},
        {4, 'e'},
        {5, 'f'},
        {6, 'g'},
        {7, 'h'},
        {8, 'i'},
        {9, 'j'},
        {10, 'k'},
        {11, 'l'},
        {12, 'm'},
        {13, 'n'},
        {14, 'o'},
        {15, 'p'},
        {16, 'q'},
        {17, 'r'},
        {18, 's'},
        {19, 't'},
        {20, 'u'},
        {21, 'v'},
        {22, 'w'},
        {23, 'x'},
        {24, 'y'},
        {25, 'z'}};
    for (auto &i : arr)
    {
        // get the value using the key from map
        char letter = alphabet.at(i % 26);

        // push the char llo the string once taken from map
        result.push_back(letter);
    }

    return result;
}

string case7(vector<ll> arr)
{
    // ll index = arr[0];
    // unordered_set<ll> llSet;

    // // initialise the set
    // llSet.insert(index);

    // while (index < arr.size())
    // {
    //     // if the current index i is index N-1, prll “Done” and stop;
    //     if (index == arr.size() - 1)
    //     {
    //         return "Done";
    //     }
    //     index = arr[index];

    //     // if element is already in the set, sound off as Cyclic
    //     // else, add element llo set
    //     if (llSet.find(index) == llSet.end())
    //     {
    //         llSet.insert(index);
    //     }
    //     else
    //     {
    //         return "Cyclic";
    //     }
    // }

    // return "Out";
    ll index = 0;
    vector<ll> visitation(arr.size(), 0);

    while (true)
    {
        if (index == arr.size() - 1)
        {
            return "Done";
        }
        if (index >= arr.size())
        {
            return "Out";
        }
        if (visitation[index])
        {
            break;
        }
        visitation[index] = 10;
        index = arr[index];
    }

    return "Cyclic";
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> arr;
    ll size = 0;
    ll t = 0;
    ll input;

    cin >> size;
    cin >> t;

    for (ll i; i <= size; ++i)
    {
        cin >> input;
        arr.push_back(input);
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
        cout << case5(arr);
        break;
    case (6):
        cout << case6(arr);
        break;
    case (7):
        cout << case7(arr);
        break;
    default:
        cout << case1(arr);
        break;
    }

    return 0;
}