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

void printVec(vector<ll> arr) {
    cout << '\n';
    for (auto& i : arr) {
        cout << i << ' ';
    }
}

ll random(ll min, ll max) {  //range : [min, max] 
    static bool first = true;
    if (first) {
        srand(time(NULL)); //seeding for the first time only!
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}

ll quickSelect(vector<ll>& arr, ll left, ll right, ll kth) {
    ll pivot = arr[right];
    ll pointer = left; // pointer starts at the front of the array, aka 0 index
    for (size_t i = left; i < right; ++i)
    {
        if (arr[i] <= pivot) { // iterate through array to find the new pivot
            swap(arr[pointer], arr[i]); // if the current pivot is too big, then swap to start from new pivot
            ++pointer; // increment pointer to find the new pivot
        }
    }
    swap(arr[pointer], arr[right]); // swap the new pointer with old pointer once new pointer found

    if (pointer < kth) { // check right of array
        return quickSelect(arr, pointer + 1, right, kth);
    }
    else if (pointer > kth) { // check left of array
        return quickSelect(arr, left, pointer - 1, kth);
    }

    return arr[pointer]; // final result
}

ll partition(vector<ll> arr, ll left, ll right) {
    ll pivot = arr[left]; // can be arr[right] also or any index within the arr
    ll i = left;
    ll j = right;
    while (i < j) {
        do {
            ++i;
        } while (arr[i] <= pivot);

        do {
            ++j;
        } while (arr[j] >= pivot);

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[left], arr[j]);

    return j;
}

void quickSort(vector<ll> arr, ll left, ll right) {
    if (left < right) {
        ll j = partition(arr, left, right);
        quickSort(arr, left, j);
        quickSort(arr, j + 1, right);
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<ll> arr = { 4, 9, 5, 1, 6, 9, 10, 5 };
    vector<ll> arr2 = arr;
    vector<ll> arr3 = arr;

    ll k = 2;
    // const ll initialPivot = random(0, arr.size() - 1); // random initial pivot, too inconsistent
    const ll initialPivot = arr.size() - 1;

    ll kth = --k; // kth smallest, is kth - 1 as input
    // ll kth = arr.size() - k; // kth largest, is arr.size() - k

    cout << quickSelect(arr, 0, initialPivot, kth) << endl;

    printVec(arr);

    /**
     * Alternative Answer
    */
    stable_sort(arr2.begin(), arr2.end());
    cout << '\n' << arr2[kth];

    printVec(arr2);

    return 0;
}