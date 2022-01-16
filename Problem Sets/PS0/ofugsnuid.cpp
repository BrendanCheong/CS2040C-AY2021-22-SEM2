// sprinkled with two subtle bugs, submitting this verbatim (what for?) will be not be AC

#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("in.txt", "r", stdin);
  int n; cin >> n;
  vector<int> l(n);
  for (auto  li : l)
    cin >> li;
  reverse(l.begin(), l.end()); // what is this?
  for (auto& li : l)
    cout << li << '\n';
  return 1;
}



// for those who also know Python
// # sprinkled with 1 bug

// n = int(input())
// L = [int(input()) for _ in range(n)]
// print(*reversed(L), sep = '\t')
