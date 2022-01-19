#include <iostream> // question 1a
#include <vector>
/**
 * 1a) You can  change <iostream> with <bits/stdc++.h> no problem
 * iostream is a header file that allows you to import & use cin and cout
 * bits/stdc++h. imports every header file including cin and cout
 *
 * 1b) No potential issues, this just means that we dont have to use std:: all the time
 * like std::cin and std::cout which is annoying to type.
 * Can also add your own stuff like using ll = long long int;
 * or using ul = unsigned long long int;
 *
 * 1c) template class is similar to generics where the input to T is the type of the class
 * when we first create a class object.
 * For example, since its <class T> and ListArray uses T
 * when we create an instance of ListArray like ListArray<int>, the type T is now int
 * for all parts of the class ListArray (Ex: T get becomes int get)
 * templates are an easy way to create a single class to work with different data types.
 *
 * 1d) The array is limited to 100 element size. It would be better if 100 was N instead imo.
 * So that we can define the size of the ListArray when creating an isntance.
 *
 * 1e) HELP: Just alternative syntax for initializing so you don't have to write stuff in the ctor body.
 * ListArray() {
 *  N = 0;
 * }
 *
 * 1f) The method to get the index in the array does not consider edge cases like
 * out of bounds cases. NOTE: C++ doesn't have out of bound errors by default.
 *
 * 1g) HELP: Why is there N == 100?
 * HELP: WHY?? N(0) is calling N's constructor (int) with 0 as the argument.
 * This is a guard clause for edge cases when there are out of bounds int selected.
 *
 * 1h) The extra for loop makes every element after the index to become the last inputted element into the method.
 * So it must be commented out or else the method won't work.
 *
 * 1i) Include guard clause for edge cases. Other than that the deleting algorithm is fine as it is.
 *
 * 1j) This line is just used to print out the contents of the list array A.
 * for each element in the array, space them out with character ' '.
 * This is because c++ has no way to actually print out the array nicely without using a for loop.
 * Same applies to vectors.
 *
 * 1k) I will attempt to make a quicksort algorithm using a pivot. Maybe I'll include
 * a bubble sort algo later.
 *
 * 1l) Yes you can! Using new just means we have to deallocate the newly created object
 * from the heap memory or else it will cause memory leaks.
 * This is because C++ is not a garbage collected language like java.
*/
using namespace std; // question 1b
template <class T>   // question 1c
class ListArray
{
private: // variables under this section is private
    // an array of 100 size is generated.
    int N;    // N stores the number of elements in the ListArray
    T A[100]; // question 1d
public:
    ListArray() : N(0) {} // question 1e
    T get(int i)
    {
        /**
         * 1f) There are no guard statements for out of bounds edge cases
         * below is the FIXED code
        */
        if (i >= N || i < 0)
        {
            return (T)-1;
        }
        return A[i]; // question 1f
    }
    int search(T v)
    {
        for (int i = 0; i < N; ++i)
            if (A[i] == v)
                return i;
        return -1;
    }

    // Insert value 'v' at index 'i'.
    // Everything after index 'i' will be shifted back by one position.
    void insert(int i, T v)
    {
        if ((N == 100) || (i < 0) || (i > N))
            return; // question 1g
        for (int j = N - 1; j >= i; j--)
            // for (int j = i; j <= N - 1; ++j) // question 1h
            A[j + 1] = A[j];
        A[i] = v;
        ++N;
    }
    // remove item at the given index
    // replace each index after the given index with the element after it
    // decrease array size after deleting array
    void remove(int i)
    {
        /**
         * 1i) Include some guard statements for edge cases like out of bounds cases
        */
        if (i < 0 || i >= N)
        {
            return;
        }
        for (int j = i; j < N - 1; ++j) // question 1i
            A[j] = A[j + 1];
        --N;
    }
    void printList()
    {
        for (int i = 0; i < N; ++i)
            cout << (i ? " " : "") << A[i]; // question 1j
        cout << '\n';
    }
    void sortList()
    {
        bubbleSort();
        //sort(A, A + N); this only works if its NOT a custom type. Else you need a comparator function
    } // sort array A, question 1k

    T bubbleSort()
    {
        for (int i = 0; i < N - 1; i++)
        { //O(N)
            for (int j = 1; j < N - i; j++)
            { //O(N)
                if (A[j - 1] > A[j])
                { //O(1)
                    int temp = A[j];
                    A[j] = A[j - 1];
                    A[j - 1] = temp;
                }
            }
        } // O(N^2)

    }

    int swap(int arr[], int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    int partition(int arr[], int l, int r)
    {
        int pivot = arr[r];
        int i = l - 1;

        for (int j = l; j < r; ++j)
        {
            if (arr[j] < pivot)
            {
                ++i;
                swap(arr, i, j);
            }
        }
    }

    void quicksort(int arr[], int l, int r)
    {
        if (l < r)
        {
            int pi = partition(arr, l, r);
            quicksort(arr, l, pi - 1);
            quicksort(arr, pi + 1, r);
        }
    }
};

int main()
{
    ListArray<int>* LA = new ListArray<int>(); // question 1l
    LA->insert(0, 5);
    LA->insert(0, 1);
    LA->insert(0, 4);
    LA->insert(0, 7);
    LA->insert(0, 2);
    LA->printList();               // we should have A = {2, 7, 4, 1, 5} by now
    cout << LA->get(3) << '\n';    // 1, A[3] = 1
    cout << LA->search(4) << '\n'; // 2, A[2] = 4
    cout << LA->search(6) << '\n'; // not found, -1
    LA->remove(1);
    cout << LA->search(4) << '\n'; // 1, A[1] = 4 now
    cout << LA->search(7) << '\n'; // not found, -1
    LA->printList();               // unsorted, A = {2, 4, 1, 5} by now
    LA->sortList();
    LA->printList(); // sorted, A = {1, 2, 4, 5} by now
    return 0;
} // please copy paste the code above, test compile, and run it yourself