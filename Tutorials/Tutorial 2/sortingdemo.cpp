#include <bits/stdc++.h>
using namespace std;

// https://visualgo.net/en/sorting?slide=7-1
void bubbleSort(int a[], int N) { // the standard version
    for (; N > 0; --N) // N iterations
        for (int i = 0; i < N - 1; ++i) // except the last, O(N)
            if (a[i] > a[i + 1]) // not in non-decreasing order
                swap(a[i], a[i + 1]); // swap in O(1)
}

// https://visualgo.net/en/sorting?slide=11-2
void merge(int a[], int low, int mid, int high) {
    // subarray1 = a[low..mid], subarray2 = a[mid+1..high], both sorted
    int N = high - low + 1;
    int b[N]; // discuss: why do we need a temporary array b?
    int left = low, right = mid + 1, bIdx = 0;
    while (left <= mid && right <= high) // the merging
        b[bIdx++] = (a[left] <= a[right]) ? a[left++] : a[right++];
    while (left <= mid) b[bIdx++] = a[left++]; // leftover, if any
    while (right <= high) b[bIdx++] = a[right++]; // leftover, if any
    for (int k = 0; k < N; ++k) a[low + k] = b[k]; // copy back
}

// https://visualgo.net/en/sorting?slide=11-5
void mergeSort(int a[], int low, int high) {
    // the array to be sorted is a[low..high]
    if (low < high) { // base case: low >= high (0 or 1 item)
        int mid = (low + high) / 2;
        mergeSort(a, low, mid); // divide into two halves
        mergeSort(a, mid + 1, high); // then recursively sort them
        merge(a, low, mid, high); // conquer: the merge routine
    }
}

// https://visualgo.net/en/sorting?slide=12-7, with two lines addition for https://visualgo.net/en/sorting?slide=13
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

void partition3way(int a[], int l, int r) {
    int i = l - 1;
    int j = r;
    int p = l - 1, q = r;
    int v = a[r];

    while (true)
    {
        // From left, find the first element greater than 
        // or equal to v. This loop will definitely terminate 
        // as v is last element 
        while (a[++i] < v);

        // From right, find the first element smaller than or 
        // equal to v 
        while (v < a[--j])
            if (j == l)
                break;

        // If i and j cross, then we are done 
        if (i >= j) break;

        // Swap, so that smaller goes on left greater goes on right 
        swap(a[i], a[j]);

        // Move all same left occurrence of pivot to beginning of 
        // array and keep count using p 
        if (a[i] == v)
        {
            p++;
            swap(a[p], a[i]);
        }

        // Move all same right occurrence of pivot to end of array 
        // and keep count using q 
        if (a[j] == v)
        {
            q--;
            swap(a[j], a[q]);
        }
    }

    // Move pivot element to its correct index 
    swap(a[i], a[r]);

    // Move all left same occurrences from beginning 
    // to adjacent to arr[i] 
    j = i - 1;
    for (int k = l; k < p; k++, j--)
        swap(a[k], a[j]);

    // Move all right same occurrences from end 
    // to adjacent to arr[i] 
    i = i + 1;
    for (int k = r - 1; k > q; k--, i++)
        swap(a[i], a[k]);
}

// https://visualgo.net/en/sorting?slide=12-8
void quickSort(int a[], int low, int high) {

    if (low < high) {
        int pivotIdx = partition(a, low, high); // O(N)
        // a[low..high] ~> a[low..pivotIdxÃ¢â‚¬â€œ1], pivot, a[pivotIdx+1..high]
        quickSort(a, low, pivotIdx - 1); // recursively sort left subarray
        // a[pivotIdx] = pivot is already sorted after partition
        quickSort(a, pivotIdx + 1, high); // then sort right subarray
    }
}

// function to perform the above algorithm
void beadSort(int data[], int count) {
    // Find the maximum element
    int i, j, max, sum;
    unsigned char* beads;

    for (i = 1, max = data[0]; i < count; ++i)
        if (data[i] > max)
            max = data[i];

    beads = (unsigned char*)calloc(1, max * count);

    for (i = 0; i < count; ++i)
        for (j = 0; j < data[i]; ++j)
            beads[i * max + j] = 1;

    for (j = 0; j < max; ++j)
    {
        for (sum = i = 0; i < count; ++i)
        {
            sum += beads[i * max + j];
            beads[i * max + j] = 0;
        }

        for (i = count - sum; i < count; ++i)
            beads[i * max + j] = 1;
    }

    for (i = 0; i < count; ++i)
    {
        for (j = 0; j < max && beads[i * max + j]; ++j);
        data[i] = j;
    }

    free(beads);
}

// to be used by various sorting algorithms
void printArray(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << a[i];
    }
    cout << "\n";
}

unsigned long long int random(int min, int max) //range : [min, max]
{
    static bool first = true;
    if (first)
    {
        srand(time(NULL)); //seeding for the first time only!
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}

const long long int MAX_N = pow(10, 3); // big enough for our demo to notice the difference
const int MIN_RANGE = 1;
const unsigned long long int MAX_RANGE = pow(10, 8);
// if you encounter runtime error/stack overflow (quite likely), you need to adjust your compilation setting to: g++ -std=gnu++17 -Wl,--stack,16777216

int main() {
    int n = MAX_N; // n = 10; // use smaller number if you intend to print the actual array before/after sorting
    int a[MAX_N];
    for (int i = 0; i < n; ++i) {
        a[i] = random(MIN_RANGE, MAX_RANGE); // [1..1000000]
    }
    int len = sizeof(a);

    clock_t begin = clock();
    // printArray(a, n);
    // bubbleSort(a, n); // very slow, do not use large MAX_N >= 10000 (will be minutes/hours...)
    // printArray(a, n);
    // cout << "Elapsed time for Bubble Sort: " << double(clock() - begin) / CLOCKS_PER_SEC << "\n";

    begin = clock();
    // printArray(a, n);
    mergeSort(a, 0, n - 1);
    // printArray(a, n);
    cout << "Elapsed time for Merge Sort: " << double(clock() - begin) / CLOCKS_PER_SEC << "\n";

    n = MAX_N;
    for (int i = 0; i < n; ++i)
        // a[i] = i; // increasing input, one of the hardest test case for (non Randomized) Quick Sort
        // a[i] = 7; // constant input, also one of the hardest test case for (WRONGLY implemented or non Randomized) Quick Sort
        a[i] = rand() % 1000000; // [1..1000000]

    begin = clock();
    // printArray(a, n);
    quickSort(a, 0, n - 1); // experiment with line 31-32 above
    // sort(a, a+n); // there is a (quicker) Quick Sort inside (called 'introsort' if I am not mistaken)
    // printArray(a, n);
    cout << "Elapsed time for Quick Sort: " << double(clock() - begin) / CLOCKS_PER_SEC << "\n";

    // begin = clock();
    // // printArray(a, n);
    // beadSort(a, MAX_N); // experiment with line 31-32 above
    // // printArray(a, n);
    // cout << "Elapsed time for Bead Sort: " << double(clock() - begin) / CLOCKS_PER_SEC << "\n";

    return 0;
}