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

class SlidingDoor {

private:
    ll MAX_JUMP = 0;
    ll startingNumber;

public:

    SlidingDoor() {}

    void setStartingNumber(ll startingNumber) {
        this->startingNumber = startingNumber;
    }

    void evaluateNumber(ll number) {
        ll distance = startingNumber - number;
        if (startingNumber > number && distance > MAX_JUMP) {
            this->MAX_JUMP = distance;
        }
    }

    ll getJump() {
        return this->MAX_JUMP;
    }

    ll getStartingNumber() {
        return this->startingNumber;
    }
};

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, ele;
    ll answerForward = 0; ll answerBackward = 0;
    bool doorOpen = true;
    vector<ll> arr;
    cin >> N;

    if (N <= 2) { // O(1)
        cout << answerForward << endl;
        return 0;
    }

    SlidingDoor door;
    cin >> ele;
    arr.push_back(ele);
    door.setStartingNumber(ele);
    for (size_t _ = 0; _ < N - 1; ++_) {
        cin >> ele;
        arr.push_back(ele);

        ll startingNumber = door.getStartingNumber();

        door.evaluateNumber(ele);
        if (ele >= startingNumber) { // only complete the window when we find a higher or equal height to build a bridge
            // find what is my current max_jump
            ll maxJump = door.getJump();
            if (maxJump > answerForward) {
                answerForward = maxJump;
                //cout << "Current Max Jump is: " << maxJump << '\n';
            }
            door.setStartingNumber(ele);
        }

        //cout << ele << " starting Number is: " << startingNumber << " max jump is: " << door.getJump() << '\n';
    }

    // get the last element of arr
    ll lastElement = arr[N - 1];
    SlidingDoor window;
    window.setStartingNumber(lastElement);
    // iterate backwards from the arr starting with the second last element
    for (vector<ll>::reverse_iterator it = arr.rbegin() + 1; it != arr.rend(); ++it) {
        ll ele = *it;
        ll startingNumber = window.getStartingNumber();

        window.evaluateNumber(ele);
        if (ele >= startingNumber) { // only complete the window when we find a higher or equal height to build a bridge
            // find what is my current max_jump
            ll maxJump = window.getJump();
            if (maxJump > answerBackward) {
                answerBackward = maxJump;
                //cout << "Current Max Jump is: " << maxJump << '\n';
            }
            window.setStartingNumber(ele);
        }
    }


    //cout << "answerForward: " << answerForward << " answerBackward: " << answerBackward << '\n';
    cout << max(answerForward, answerBackward);

    return 0;
}