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

void printList(list<char>& list) {
    for (auto it = list.begin(); it != list.end(); it++) {
        cout << *it;
    }
    cout << '\n';
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T = 0;
    string input;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (size_t i = 0; i < T; ++i) {
        getline(cin, input);
        ll index = 0;
        list<char> arr;
        list<char>::iterator pointer = arr.begin();
        for (char letter : input) {
            switch (letter) {
            case('<'):
                if (index != 0) {
                    list<char>::iterator temp = pointer; // pointer auto adjusts with change in list
                    temp = prev(temp, 1);
                    arr.erase(temp);
                    index -= 1;
                }
                break;
            case('['):
                pointer = arr.begin();
                index = 0;
                break;
            case(']'):
                pointer = arr.end();
                index = arr.size();
                break;
            default:
                arr.insert(pointer, letter);
                ++index;
                break;
            }
        }
        printList(arr);
    }
    return 0;
}