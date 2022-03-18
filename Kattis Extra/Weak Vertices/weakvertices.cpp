#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (true) {
        int n; cin >> n;
        if (n == -1) // if we reach -1, end simulation
            return 0;
        int AM[20][20]; // form the adjency matrix
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) // O(n^2)
                cin >> AM[i][j];
        // identify weak vertices
        for (int i = 0; i < n; i++) { // O(n^3)
            bool weak = true;
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    if (AM[i][j] && AM[i][k] && AM[k][j]) // check all 3 vertices
                        weak = false;
            if (weak)
                cout << i << " ";
        }
    }

    return 0;
}