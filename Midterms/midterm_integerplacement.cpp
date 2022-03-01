#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("in_integerplacement.txt", "r", stdin);
  int n; cin >> n; cin.ignore();
  vector<int> v(n);
  for (auto& vi : v)
    cin >> vi;
  cin.ignore(); // the new line
  vector<char> c(n-1);
  for (auto& ci : c) {
    cin >> ci;
    cin.ignore(); // a space or a new line
  }

  sort(v.begin(), v.end()); // for best O(n) performance of our question, use radix sort instead of std::sort, if not algo is O(n log n)
  
  int i = 0, j = n-1; // i/j are front/back pointers, respectively
  for (auto& ci : c) {
    if (ci == '<') // greedily put the smallest element
      cout << v[i++] << ci; // post increment later
    else // if (ci == '>') greedily put the largest element
      cout << v[j--] << ci; // post decrement later
  }
  cout << v[i] << '\n'; // the last one
  return 0;
}
