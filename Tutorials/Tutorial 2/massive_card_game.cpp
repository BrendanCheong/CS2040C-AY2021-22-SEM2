#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long int;

ll binarySearchForLeftRange(vector<ll> arr, ll left) {
    if (arr[arr.size() - 1] < left)
        return -1;

    ll start = 0;
    ll end = arr.size() - 1;

    while (start <= end) {

        ll mid = start + ((end - start) / 2);

        if (arr[mid] >= left)
            end = mid - 1; // make the pointer go left
        else
            start = mid + 1; // make the pointer go right
    }

    return end + 1;
}

ll binarySearchForRightRange(vector<ll> arr, ll right) {
    if (arr[0] > right)
        return -1;

    ll start = 0;
    ll end = arr.size() - 1;

    while (start <= end) {
        ll mid = start + ((end - start) / 2);

        if (arr[mid] > right)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return start - 1;
}

void qsort(vector<ll>& arr, ll N)
{
    ll lPivot = arr[N - 1];
    ll lIndexOfLargestElement = 0;
    for (size_t i = 0; i < N - 1; ++i) {
        if (arr[i] < lPivot) {
            // Swap largest element with this
            swap(arr[i], arr[lIndexOfLargestElement]);
            lIndexOfLargestElement++;
        }
    }
    // swap pivot with arr[lIndexOfLargestElement]
    swap(arr[N - 1], arr[lIndexOfLargestElement]);

    if (lIndexOfLargestElement > 1) {
        qsort(arr, lIndexOfLargestElement);
    }

    if (N - lIndexOfLargestElement - 1 > 1) {

        qsort(arr, N - lIndexOfLargestElement - 1);
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, cards, Q = 0;
    vector<ll> cardArray;

    cin >> N;
    for (size_t i = 0; i < N; i++) {
        cin >> cards;
        cardArray.push_back(cards);
    }

    // qsort(cardArray, cardArray.size());
    // mergeSort(cardArray, 0, N - 1);
    sort(cardArray.begin(), cardArray.end());

    cin >> Q;
    for (size_t i = 0; i < Q; i++) {
        ll left, right, index1, index2;
        cin >> left >> right;
        index1 = binarySearchForLeftRange(cardArray, left);
        index2 = binarySearchForRightRange(cardArray, right);
        if (index1 == -1 || index2 == -1 || index1 > index2) {
            cout << 0 << '\n';
        }
        else {
            cout << (index2 - index1 + 1) << '\n';
        }
    }

    return 0;
}