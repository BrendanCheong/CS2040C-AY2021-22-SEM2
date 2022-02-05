#include <bits/stdc++.h>
using namespace std;
#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

void printArray(int A[], int N) {
  for (int i = 0; i < N; ++i) {
    cout << A[i] << " ";
  }
  cout << endl;
}

void insertionSort(int A[], int N) {
  for (int i = 1; i < N; i++) { // 4 passes
    int e = A[i]; int j = i;
    while (j > 0) {
      if (A[j - 1] > e) {
        cout << "compared! \n";
        A[j] = A[j - 1];
      }
      else
        break;
      j--;
    }
    A[j] = e;
  }
}

void selectionSort(int A[], int N) {
  for (int i = 0; i < N - 1; i++) { // 3 passes
    int cur_min = i;
    for (int j = i + 1; j < N; j++) {
      if (A[j] < A[cur_min]) {
        cout << "compared! \n";
        cur_min = j;
      }
      swap(A[i], A[cur_min]);
    }
  }
}

void bubbleSort(int A[], int N) { // the standard version
  for (int j = 0; j < N; j++) {// 3 passes
    for (int i = 0; i < N - j - 1; i++) {
      if (A[i] > A[i + 1]) {
        cout << "swapped! \n";
        swap(A[i], A[i + 1]);
      }
    }
  }
}

void bubble2(int A[], int n) {
  int j = 0;
  bool swapped;
  do {
    bool swapped = false; j++;
    for (int i = 0; i < n - j; i++) // each completion of this for-loop is counted as one pass
      if (A[i] > A[i + 1]) { // each execution of this if-statement is counted as one comparison
        swap(A[i], A[i + 1]);
        cout << "swapped" << '\n';
        swapped = true;
      }
  } while (swapped);
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
      swap(a[k], a[m]); // C++ STL algorithm std::swap
    } // notice that we do nothing in case 1: a[k] > p
  }
  swap(a[i], a[m]); // final step, swap pivot with a[m]
  return m; // return the index of pivot, to be used by Quick Sort
}

void quickSort(int a[], int low, int high) {

  if (low < high) {
    int pivotIdx = partition(a, low, high); // O(N)
    cout << "my pivot is: " << a[pivotIdx] << '\n';
    // a[low..high] ~> a[low..pivotIdxÃ¢â‚¬â€œ1], pivot, a[pivotIdx+1..high]
    quickSort(a, low, pivotIdx - 1); // recursively sort left subarray
    // a[pivotIdx] = pivot is already sorted after partition
    quickSort(a, pivotIdx + 1, high); // then sort right subarray
  }
}

int main() {

  int array[] = { 14, 40, 16, 4, 38, 17 };
  int N = NELEMS(array);

  // selectionSort(array, N);
  // insertionSort(array, N);
  bubbleSort(array, N);
  // quickSort(array, 0, N - 1);
  printArray(array, N);

  return 0;
}