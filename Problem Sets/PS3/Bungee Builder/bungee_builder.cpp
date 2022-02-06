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

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // in this case we need to have a stack of integers
    // create a varaible called answer = 0;
    // given a stream of numbers, start the first number as the begining of the stack
    // then keep adding on to this UNTIL we find a number BIGGER THAN THE BEGINING
    // during that, we will find the min number, the min number IS NOT THE BEGINING and NOT THE number thats BIGGER THAN THE BEGINING.
    // The min number starts of as 0, create another variable called AMOUNT_IN_STACK.
    // if AMOUNT_IN_STACK = 0, then return 0 as there is no bridge
    // else, keep updating the min number and ++AMOUNT_IN_STACK.
    // when we find a number that is BIGGER THAN THE BEGINING, simply take BEGINING - min number, and if answer < that equation, make answer = equation.
    // now the begining number = BIGGER THAN THE BEGINING and repeat the process.

    // DO THE SAME thing once N is finished BUT BACKWARDS.

    // create a class to do this, it handles this "sliding door", this "sliding door" only changes the answer if answer < that equation

    return 0;
}
