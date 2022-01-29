#include <bits/stdc++.h>
using namespace std;

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
    int left = low;
    int right = mid + 1;
    int bIdx = 0;
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
vector<double> QuickSort(vector<double>& vec1) {

    double i = 0;
    double j = vec1.size() - 2;
    double tmp;
    int pivotindex = vec1.size() - 1;
    double pivot = vec1[pivotindex];

    if (vec1.size() <= 1)
        return vec1;


    while (i <= j) {
        while (vec1[i] < pivot) {
            i++;
        }
        while (vec1[j] > pivot)
            j--;
        if (i <= j) {
            tmp = vec1[i];
            vec1[i] = vec1[j];
            vec1[j] = tmp;
            i++;
            j--;
        }
    }
    // pivot change
    vec1[pivotindex] = vec1[i];
    vec1[i] = pivot;
    pivotindex = i;

    if (vec1.size() <= 2)
        return vec1;
    // partition
    vector<double> left_vec, right_vec;
    vector<double>::iterator pivotiter = vec1.begin() + pivotindex;
    copy(vec1.begin(), pivotiter, back_inserter(left_vec));
    copy(pivotiter + 1, vec1.end(), back_inserter(right_vec));


    if (left_vec.size() > 0) {
        QuickSort(left_vec);
        copy(left_vec.begin(), left_vec.end(), vec1.begin());
    }
    if (right_vec.size() > 0) {
        QuickSort(right_vec);
        copy(right_vec.begin(), right_vec.end(), pivotiter + 1);
    }
    return vec1;
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

void printVector(vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        if (i > 0) cout << " ";
        cout << arr[i];
    }
    cout << "\n";
}

vector<int> quickSortVector(vector<int>& arr) {
    vector<int> dummy;
    if (arr.size() <= 1)
        return dummy;
    int pivot = arr[random(0, arr.size() - 1)];
    vector<int> left, right;
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] < pivot)
            left.push_back(arr[i]);
        else
            right.push_back(arr[i]);
    }
    quickSortVector(left);
    quickSortVector(right);
    // arr.clear(); // O(n^2) to clear, might be better to create a new array instead
    left.push_back(pivot);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

void mergeVec(vector<int>& a, int low, int mid, int high) {
    // subarray1 = a[low..mid], subarray2 = a[mid+1..high], both sorted
    int N = high - low + 1;
    vector<int> b(N); // discuss: why do we need a temporary array b?
    int left = low;
    int right = mid + 1;
    int bIdx = 0;
    while (left <= mid && right <= high) // the merging
        b[bIdx++] = (a[left] <= a[right]) ? a[left++] : a[right++];
    while (left <= mid) b[bIdx++] = a[left++]; // leftover, if any
    while (right <= high) b[bIdx++] = a[right++]; // leftover, if any
    for (int k = 0; k < N; ++k) a[low + k] = b[k]; // copy back
}

// https://visualgo.net/en/sorting?slide=11-5
void mergeSortVec(vector<int>& a, int low, int high) {
    // the array to be sorted is a[low..high]
    if (low < high) { // base case: low >= high (0 or 1 item)
        int mid = (low + high) / 2;
        mergeSortVec(a, low, mid); // divide into two halves
        mergeSortVec(a, mid + 1, high); // then recursively sort them
        mergeVec(a, low, mid, high); // conquer: the merge routine
    }
}

const long long int MAX_N = pow(10, 6); // big enough for our demo to notice the difference
const int MIN_RANGE = 1;
const unsigned long long int MAX_RANGE = pow(10, 4);
// if you encounter runtime error/stack overflow (quite likely), you need to adjust your compilation setting to: g++ -std=gnu++17 -Wl,--stack,16777216

int main() {
    int n = MAX_N; // n = 10; // use smaller number if you intend to print the actual array before/after sorting
    int a[MAX_N];
    vector<int> vec1(MAX_N, 0);
    for (int i = 0; i < n; ++i) {
        a[i] = random(MIN_RANGE, MAX_RANGE); // [1..1000000]
        vec1[i] = a[i];
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
    // vector<int> sortedVec = quickSortVector(vec1); // experiment with line 31-32 above
    // // sort(a, a+n); // there is a (quicker) Quick Sort inside (called 'introsort' if I am not mistaken)
    // // printVector(sortedVec);
    // cout << "Elapsed time for Quick Sort Vector: " << double(clock() - begin) / CLOCKS_PER_SEC << "\n";

    begin = clock();
    // printArray(a, n);
    mergeSortVec(vec1, 0, n - 1); // experiment with line 31-32 above
    // sort(a, a+n); // there is a (quicker) Quick Sort inside (called 'introsort' if I am not mistaken)
    // printVector(vec1);
    cout << "Elapsed time for Merge Sort Vector: " << double(clock() - begin) / CLOCKS_PER_SEC << "\n";

    // begin = clock();
    // // printArray(a, n);
    // beadSort(a, MAX_N); // experiment with line 31-32 above
    // // printArray(a, n);
    // cout << "Elapsed time for Bead Sort: " << double(clock() - begin) / CLOCKS_PER_SEC << "\n";

    return 0;
}