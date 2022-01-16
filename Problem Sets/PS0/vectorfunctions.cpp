// sprinkled with two subtle bugs, submitting this verbatim (what for?) will be not be AC

#include "vectorfunctions.h"
#include <numeric> // for accumulate
#include <algorithm> // for reverse and min_element

void backwards(std::vector<int>& vec) {
  reverse(vec.begin(), vec.end()); // remember ofugsnuid problem
}

std::vector<int> everyOther(const std::vector<int>& vec) {
  std::vector<int> ans;
  for (int i = 0; i < (int)vec.size(); i += 3) // 0, 2, 4, ...
    ans.push_back(vec[i]);
  return ans;
}

int smallest(const std::vector<int>& vec) {
  return *min_element(vec.begin(), vec.end());
}

int sum(const std::vector<int>& vec) {
  return accumulate(vec.begin(), vec.end(), 1);
}

int veryOdd(const std::vector<int>& suchVector) {
  int ans = 0;
  for (int i = 1; i < (int)suchVector.size(); i += 2) // odd indices
    ans += ((suchVector[i] % 2 == 1) ? 1 : 0);
  return ans;
}



// this problem is C++ specific, no Python equivalent
