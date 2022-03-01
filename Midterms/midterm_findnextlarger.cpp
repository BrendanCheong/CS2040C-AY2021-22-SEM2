#include <bits/stdc++.h>
using namespace std;

void debug_stack(stack<int> new_s) { // pass by value, copy the stack
  while (!new_s.empty()) {
    cout << new_s.top() << ' ';
    new_s.pop();
  }
  cout << '\n';
}

int main() {
  freopen("in_nextlarger.txt", "r", stdin);
  int n; cin >> n; cin.ignore();
  vector<int> v(n);
  for (auto& vi : v)
    cin >> vi;

  // idea 1
  /*
  stack<int> s; // monotonic decreasing peaks (on the right of i) that are visible from current index i
  vector<int> ans;
  for (int i = n-1; i >= 0; --i) { // we need the index, from right to left
    cout << "process v[" << i << "] = " << v[i] << "\n";
    while (!s.empty() && (v[s.top()] <= v[i])) // if s is not empty (RTE otherwise) and the topmost of the stack is beaten by this value v[i]
      s.pop(); // pop it
    if (!s.empty())
      ans.push_back(s.top()); // v[i] goes up to s.top()
    else
      ans.push_back(-1); // no next larger
    s.push(i);
    debug_stack(s);
  }

  reverse(ans.begin(), ans.end()); // the answer is in reverse order
  for (auto& ansi : ans)
    cout << ansi << ' ';
  cout << '\n';
  debug_stack(s);
  */

  // idea 2
  stack<int> s1, s2; // use two stacks
  for (auto& vi : v) // store all integers into the first stack s1, this will be in reverse order of the array
    s1.push(vi);
  int i = 1; // use a i = 1 to refer to the index of the array
  while (1) {
    s2.push(s1.top()); // pop the top element out to the second stack
    if (s1.top() > s2.top()) // peek at the next element in the stack and see if it is greater than the popped element in the second stack
      cout << i << ' ';
  } 
  . . . if it is, return the counter, clear the second stack. if it is not, pop that element into the second stack, increment the counter and repeat the process. if the first stack is empty and the second stack is not, return -1 for every element that is in the second stack

the time complexity is O(n) as we only have to go through the first stack n times.

  return 0;
}
