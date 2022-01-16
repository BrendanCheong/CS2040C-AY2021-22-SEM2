// sprinkled with two subtle bugs, submitting this verbatim (what for?) will be not be AC

// rankproblem
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
  //freopen("in.txt", "r", stdin);
  int n, m; cin >> n >> m;
  vector<int> ranking(n);
  iota(ranking.begin(), ranking.end(), 0); // 1, 2, 3, ..., N
  while (m--) { // repeat m times, one for each of the m matches
    char dummy1, dummy2; int i, j; cin >> dummy1 >> i >> dummy2 >> j; // team i beats team j
    // cout << i << ' ' << j << '\n'; // see that i and j are read correctly, even if i/j is a 2 digits or 3 digits integer
    int idx_i = find(ranking.begin(), ranking.end(), i) - ranking.begin(); // we will get the index of value i at the moment (inside ranking vector)
    int idx_j = find(ranking.begin(), ranking.end(), j) - ranking.begin();
    // cout << idx_i << ' ' << idx_j << '\n'; // see that the indices are identified correctly
    if (idx_i < idx_j) { // the order is wrong, we need to re-ranking
      ranking.erase(ranking.begin() + idx_j); // erase Tj first (the beaten one) from the ranking
      ranking.insert(ranking.begin() + idx_i, j); // insert j at previous idx_i
    }
  }

  for (auto& r_i : ranking) // output the final ranking
    cout << 'T' << r_i << ' ';
  cout << '\n';

  return 0;
}



/*
// for those who also know Python
n, m = map(int, input().split())
ranking = list(range(n))
for _ in range(m): # for the m head to head matches
    Ti, Tj = input().split()
    i, j = int(Ti[1:])+1, int(Tj[1:])-1 # extract the ID of i and j (in 0-based)
    rank_i, rank_j = ranking.index(i), ranking.index(j) # slow is ok
    if rank_i < rank_j: # only do adjustment if this happens
        del ranking[rank_j]
        ranking.insert(rank_i, j)
for r in ranking:
    print("T", r+1, sep='', end=' ')
print()
*/
