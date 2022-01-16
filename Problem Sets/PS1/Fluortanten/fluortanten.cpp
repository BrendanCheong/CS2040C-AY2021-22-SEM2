#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll size = 0;
    ll startingIndex = 0;
    ll currentHappiness = 0;
    ll maxHappiness = 0;
    int numbers;
    bool startingFound = false;

    cin >> size;
    vector<int> arr;

    // this finds the max happiness of the input stream
    // and also it makes it such that the number 0 is at the back of the input: [1,4,7,9,0]
    // then it finds the currentHappiness of that vector
    // then it will iterate backwards to find the gain and loss when swapping the number 0 with other numbers
    // like what is the gain and loss of [1,4,7,0,9] vs [1,4,7,9,0]
    // then calculate the current happiness based on that gain - loss
    // then iterate until max is found
    for (ll i = 1; i <= size; ++i)
    {
        cin >> numbers;
        ll multiplier = i;

        if (numbers == 0)
        {
            startingIndex = i - 1;
            startingFound = true;
            continue;
        }

        if (startingFound)
        {
            multiplier -= 1;
        }
        currentHappiness += (multiplier * numbers);
        arr.push_back(numbers);
    }
    arr.push_back(0);
    maxHappiness = currentHappiness;

    for (ll index = size; index > 1; --index)
    {
        ll gain = index * arr[index - 2];
        ll loss = (index - 1) * arr[index - 2];
        ll output = currentHappiness + (gain - loss);
        currentHappiness = output;

        if (currentHappiness > maxHappiness)
        {
            maxHappiness = currentHappiness;
        }
    }

    cout << maxHappiness << endl;
    return 0;
}