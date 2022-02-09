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

// create a function that prints a list of strings that takes in a list<string>
void printList(list<string>& list) {
    for (auto it = list.begin(); it != list.end(); it++) {
        cout << *it;
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, finalFirst;
    string finalAnswers = "";
    cin >> N;
    ll ops = N - 1;
    map<ll, list<string>> dict;

    for (ll i = 0; i < N; i++) {
        string name;
        cin >> name;
        dict[i + 1] = list<string>{ name };
    }

    if (N == 1) { // for that damn edge case of N = 1, why would N = 1 ??????? stupid qns
        printList(dict[N]);
        return 0;
    }

    for (size_t i = 0; i < ops; i++) {
        ll first, second;
        cin >> first >> second;

        if ((N - 2) == i) {
            finalFirst = first;
        }
        auto it = dict[first].end();
        dict[first].splice(it, dict[second]); // O(1) because we are just connecting 2 nodes together
        // how splice works is that it connects the tail of the list to the head of the input list
        // since its a linked list (DLL), I dont need to iterate through the input list in O(N)
        // making this operation at O(1) speed
    }

    printList(dict[finalFirst]);

    return 0;
}