// if your compiler can compile this, it is C++17 compliant

#include <bits/stdc++.h> // for visual studio, do not use this 'non-standard' shortcut
// #include <iostream> // but #include <iostream> and <map> instead
// #include <map>
using namespace std;
int main() {
  //cout << "hi cs2040c students s2 ay21/22\n";
  map<string, int> mapper = {{"Z", 2040}, {"Steven", 7}, {"AAAAA", 10}};
  for (auto &[k, v] : mapper)
    cout << k << "->" << v << "\n";
  return 0;
}

// if you run this program, the output should be:
/*

AAAAA->10
Steven->7
Z->2040

*/

// we will revisit map in Week 08 (Balanced BST)
