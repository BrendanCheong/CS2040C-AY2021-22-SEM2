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

class Teque {
private:
    deque<ull> dq1;
    deque<ull> dq2;
    bool flip = false;
public:
    Teque() {};

    void push_back(ull v) {
        dq1.push_back(v);
        if (!flip) {
            dq2.push_back(dq1[0]);
            dq1.pop_front();
        }

        this->flip = !flip;
    }

    void push_front(ull v) {
        dq2.push_front(v);
        if (flip) {
            ull index = dq2.size() - 1;
            dq1.push_front(dq2[index]);
            dq2.pop_back();
        }

        this->flip = !flip;
    }

    void push_middle(ull v) {
        (dq2.size() > dq1.size())
            ? dq1.push_front(v)
            : dq2.push_back(v);
        this->flip = !flip;
    }

    void get(ull v) {
        v >= dq2.size()
            ? cout << dq1[v - dq2.size()] << endl
            : cout << dq2[v] << endl;
        // printBothQueues();
    }

    void printBothQueues() {
        cout << "dq1: ";
        for (auto& i : dq1) {
            cout << i << ", ";
        }
        cout << endl;
        cout << "dq2: ";
        for (auto& i : dq2) {
            cout << i << ", ";
        }
        cout << endl;
    }
};

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ull N, x;
    string S;
    deque<ull> dq1, dq2;
    unordered_map<string, ull> dct = {
        {"push_back", 1},
        {"push_front", 2},
        {"push_middle", 3},
        {"get", 4}
    };

    cin >> N;
    Teque teque;
    for (size_t i = 0; i < N; ++i) {
        cin >> S >> x;
        switch (dct[S]) {
        case(1):
            teque.push_back(x);
            break;
        case(2):
            teque.push_front(x);
            break;
        case(3):
            teque.push_middle(x);
            break;
        default:
            teque.get(x);
            break;
        }
    }

    return 0;
}