#include <bits/stdc++.h>
using namespace std;

// upgraded version of https://visualgo.net/en/sorting?slide=12-7, with two lines addition for https://visualgo.net/en/sorting?slide=13
pair<int, int> threewaypartition(int a[], int lo, int hi) {
  // // ================== the only addition for Randomized Quick Sort
  // int r = lo + rand()%(hi-lo+1); // a random index between [lo..hi]
  // swap(a[lo], a[r]); // tada
  // ==================
  int p = a[lo]; // p = a[lo] (first index in [lo..hi]) is always the pivot
  pair<int, int> idxs = {-1, -1}; // overwrite this
  int i = lo; // one beyond the end index of red (< p) region, common mistake is to put i = 0 here
  int j = lo; // one beyond the end index of white (== p) region, common mistake is to put j = 0 here
  int k = hi; // one less than the start index of blue (> p) region, common mistake is to put k = (hi-lo+1)-1 here
  while (j <= k) {
    if (a[j] < p) { // red (< p) region
      // cout << "throw a[" << j << "] = " << a[j] << " to red (< p) region, swap with a[" << i << "] = " << a[i] << '\n';
      swap(a[i++], a[j++]); // post increment i and j AFTER swap
    }
    else if (a[j] > p) { // blue (> p) region
      // cout << "throw a[" << j << "] = " << a[j] << " to blue (> p) region, swap with a[" << k << "] = " << a[k] << '\n';
      swap(a[j], a[k--]); // post decrement k AFTER swap, do not touch j
    }
    else { // white (== p) region
      // cout << "put a[" << j << "] = " << a[j] << " to white (== p) region\n";
      ++j;
    }
  }
  // cout << "i = " << i << " and k = " << k << '\n';
  // assert(i <= k);
  idxs = {i, k}; // return the ind(ices) that are equal to pivot, to be used by Quick Sort
  return idxs; // first/second in ans pair = st/en ind(ices) of a == pivot
}

// upgraded version of https://visualgo.net/en/sorting?slide=12-8
void quickSort(int a[], int low, int high) {
  if (low < high) {
    // cout << "qSort a[" << low << ".." << high << "]\n";
    auto [st, en] = threewaypartition(a, low, high);
    // for (int i = low; i <= high; ++i)
    //   cout << a[i] << ' ';
    // cout << '\n';
    // // a[low..high] ~> a[low..st-1], pivot = a[st..en], a[en+1..high]
    quickSort(a, low, st-1); // recursively sort left subarray
    // // a[st..en] = pivot is/are already sorted after partition
    quickSort(a, en+1, high); // then sort right subarray
  }
}

// to be used by various sorting algorithms
void printArray(int a[], int n) {
  for (int i = 0; i < n; ++i) {
    if (i > 0) cout << ' ';
    cout << a[i];
  }
  cout << '\n';
}

const int MAX_N = 200000; // big enough for our demo to notice the difference, use smaller number if you intend to print the actual array before/after sorting
// if you encounter runtime error/stack overflow (quite likely), you need to adjust your compilation setting to: g++ -std=gnu++17 -Wl,--stack,16777216

int main() {
  int tc1[] = {1, 2, 3, 4, 5, 6, 7};
  auto [st1, en1] = threewaypartition(tc1, 0, 6);
  cout << st1 << ' ' << en1 << '\n'; // [0..0]
  assert((st1 == 0) && (en1 == 0));

  int tc2[] = {4, 2, 3, 1, 5, 6, 7};
  auto [st2, en2] = threewaypartition(tc2, 0, 6);
  cout << st2 << ' ' << en2 << '\n'; // [3..3]
  assert((st2 == 3) && (en2 == 3));

  int tc3[] = {4, 2, 3, 4, 1, 5, 6, 7, 4};
  auto [st3, en3] = threewaypartition(tc3, 0, 8);
  cout << st3 << ' ' << en3 << '\n'; // [3..5]
  assert((st3 == 3) && (en3 == 5));

  int tc4[] = {7, 7, 7, 7, 7, 7, 7};
  auto [st4, en4] = threewaypartition(tc4, 0, 6);
  cout << st4 << ' ' << en4 << '\n'; // [0..6]
  assert((st4 == 0) && (en4 == 6));

  int n = MAX_N;
  int a[MAX_N];
  for (int i = 0; i < n; ++i)
    // a[i] = i; // increasing input, one of the hardest test case for (non Randomized) Quick Sort
    // a[i] = 7; // constant input, also one of the hardest test case for (WRONGLY implemented or non Randomized) Quick Sort
    a[i] = rand()%1000000; // [0..1000000-1]

  // printArray(a, n);
  // auto [i, j] = threewaypartition(a, 0, n-1);
  // cout << i << ' ' << j << '\n';
  // printArray(a, n);

  clock_t begin = clock();
  // printArray(a, n);
  quickSort(a, 0, n-1);
  // // sort(a, a+n); // there is a (quicker) Quick Sort inside (called 'introsort' if I am not mistaken)
  // printArray(a, n);
  cout << "Is sorted check = " << is_sorted(a, a+n) << ", elapsed time for Quick Sort: " << double(clock() - begin) / CLOCKS_PER_SEC << '\n';
  assert(is_sorted(a, a+n));

  return 0;
}
