#include <bits/stdc++.h>
using namespace std;
#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

void printArray(int A[], int N) {
  for (int i = 0; i < N; ++i) {
    cout << A[i] << " ";
  }
  cout << endl;
}

void insertionSort(int A[], int N, int limiter) { //! No swaps = stable
  int compared = 0;
  for (int i = 1; i <= limiter; i++) { // 4 passes
    int e = A[i];
    int j = i; // last sorted index
    while (j > 0) { // loops until we an index that can put the element, by reducing the last sorted index j
      if (A[j - 1] > e) {
        ++compared;
        A[j] = A[j - 1]; // this does not preserve the relative order of equal elements, as the sort key is lost UNSTABLE
      }
      else {
        ++compared;
        break;
      } // break loop and insert the element
      j--; // reduce last sorted index j until we reach the correct place to put the element
    }
    A[j] = e; // inserts the element after break
  }
  cout << "No. of comparisons: " << compared << endl;
}

void selectionSort(int A[], int N, int limiter) {
  int compared = 0;
  if (limiter == N)
    --limiter;
  for (int i = 0; i < limiter; i++) { // 3 passes, N - 1
    int cur_min = i;
    for (int j = i + 1; j < N; j++) {
      if (A[j] < A[cur_min]) {
        cur_min = j;
      }
      ++compared;
    }
    swap(A[i], A[cur_min]); // preserves the relative order of keys, STABLE
  }

  cout << "No. of comparisons: " << compared << endl;
}

void bubbleSort(int A[], int N, int limiter) { // the standard version
  int swaps = 0;
  int passes = 0;
  for (int j = 0; j < limiter - 1; j++) {// 3 passes
    for (int i = 0; i < N - j - 1; i++) {
      if (A[i] > A[i + 1]) {
        // cout << "swapped! \n";
        ++swaps;
        swap(A[i], A[i + 1]); // !preserves the relative order of keys, STABLE, when comparing we skip elements with same keys. Compares same keys as same value
      }
    }
    ++passes;
  }
  cout << "No. of swaps: " << swaps << '\n';
  cout << "No. of passes: " << passes << '\n';
  /**
   * Also bubble sort starts from beginning to end, so at any point the equal keys get swapped, it will cancel out in next interation
   * 4a 4b 1 2 3 5
   * 4b 4a 1 2 3 5
   * 4b 1 2 3 4a 5
   * 1 2 3 4a 4b 5, we need < NOT  <=
   **/
}

void bubble2(int A[], int N) { // the Optimised bubblesort version, where we wont do O(n^2) on sorted ascending array
  int j = 0;
  bool swapped = false;
  int comparisons = 0;
  int excess = 0;
  int passes = 0;
  do {
    swapped = false; ++j; ++passes;
    for (int i = 0; i < N - j; ++i) {
      if (A[i] > A[i + 1]) {
        swap(A[i], A[i + 1]);
        swapped = true;
        ++comparisons;
        ++excess;
      }
      ++comparisons;
    }
  } while (swapped);

  cout << "No. of comparisons: " << comparisons - excess << '\n';
  cout << "No. of passes: " << passes << '\n';
}

int partition(int a[], int i, int j) {
  // ================== the only addition for Randomized Quick Sort
  int r = i + rand() % (j - i + 1);
  swap(a[i], a[r]); // tada
  // ==================
  int p = a[i]; // p is the pivot
  int m = i; // S1 and S2 are initially empty
  for (int k = i + 1; k <= j; ++k) { // explore the unknown region
    if ((a[k] < p) || ((a[k] == p) && (rand() % 2 == 0))) { // case 2 (PATCHED solution to avoid TLE O(N^2) on input array with identical values)
      ++m;
      swap(a[k], a[m]); // !C++ STL algorithm std::swap, because it swaps, UNSTABLE
    } // notice that we do nothing in case 1: a[k] > p
  }
  swap(a[i], a[m]); // final step, swap pivot with a[m]
  return m; // return the index of pivot, to be used by Quick Sort
}

void quickSort(int a[], int low, int high) {

  if (low < high) {
    int pivotIdx = partition(a, low, high); // O(N)
    cout << "my pivot is: " << a[pivotIdx] << '\n';
    // a[low..high] ~> a[low..pivotIdx], pivot, a[pivotIdx+1..high]
    quickSort(a, low, pivotIdx - 1); // recursively sort left subarray
    // a[pivotIdx] = pivot is already sorted after partition
    quickSort(a, pivotIdx + 1, high); // then sort right subarray
  }
}

void pivotChecker(int A[], int N) {
  int ans = 0;
  const int SMALLER = 1;
  const int LARGER = 0;
  for (int i = 0; i < N; i++) {
    unordered_set<int> left;
    for (int j = 0; j < N; j++) {
      if (i == j) break;
      if (A[j] < A[i])
        left.insert(SMALLER);
      else
        left.insert(LARGER);
    }
    unordered_set<int> right;
    for (int k = N - 1; k >= 0; k--) {
      if (i == k) break;
      if (A[k] < A[i])
        right.insert(SMALLER);
      else
        right.insert(LARGER);
    }

    if (right.size() == 1 && left.size() == 1) {
      ++ans;
      cout << A[i] << '\n';
    }
  }
  cout << "No. of potential pivots: " << ans << '\n';
}

int main() {

  int array[] = { 108, 100, 103, 101, 109, 106, 107, 102, 105, 111, 114 };
  int N = NELEMS(array);
  int limiter = N; //! default is N

  // selectionSort(array, N, limiter);
  // insertionSort(array, N, limiter);
  // bubbleSort(array, N, limiter);
  // bubble2(array, N);
  // quickSort(array, 0, N - 1);
  pivotChecker(array, N); //! this doesn't work lol, just do it mannually 
  printArray(array, N);

  return 0;
}