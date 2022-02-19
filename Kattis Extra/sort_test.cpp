#include <bits/stdc++.h>
using namespace std;
#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

void printArray(int A[], int N) {
  for (int i = 0; i < N; ++i) {
    cout << A[i] << " ";
  }
  cout << endl;
}

void insertionSort(int A[], int N) { //! No swaps = stable
  int compared = 0;
  for (int i = 1; i < N; i++) { // 4 passes
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

void selectionSort(int A[], int N) {
  int compared = 0;
  for (int i = 0; i < N - 1; i++) { // 3 passes, N - 1
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

void bubbleSort(int A[], int N) { // the standard version
  int comparisons = 0;
  int passes = 0;
  for (int j = 0; j < N; j++) {// 3 passes
    for (int i = 0; i < N - j - 1; i++) {
      if (A[i] > A[i + 1]) {
        cout << "swapped! \n";
        ++comparisons;
        swap(A[i], A[i + 1]); // !preserves the relative order of keys, STABLE, when comparing we skip elements with same keys. Compares same keys as same value
      }
    }
    ++passes;
  }
  cout << "No. of comparisons: " << comparisons << '\n' << endl;
  /**
   * Also bubble sort starts from beginning to end, so at any point the equal keys get swapped, it will cancel out in next interation
   * 4a 4b 1 2 3 5
   * 4b 4a 1 2 3 5
   * 4b 1 2 3 4a 5
   * 1 2 3 4a 4b 5, we need < NOT  <=
   **/
}

void bubble2(int A[], int N) { // the Optimised bubblesort version, where we wont do O(n^2) on sorted ascending array
  int comparisons = 0;
  int burst, i = 0;
  do {
    for (i = 0, burst = 0; i < N - 1; i++) {
      if (A[i] > A[i + 1]) {
        swap(A[i], A[i + 1]);
        burst++;
      }
      ++comparisons;
    }
  } while (burst != 0);

  cout << "No. of comparisons: " << comparisons << endl;
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

int main() {

  int array[] = { 27, 8, 28, 17, 21, 29 };
  int N = NELEMS(array);

  // selectionSort(array, N);
  // insertionSort(array, N);
  // bubbleSort(array, N);
  bubble2(array, N);
  // quickSort(array, 0, N - 1);
  printArray(array, N);

  return 0;
}