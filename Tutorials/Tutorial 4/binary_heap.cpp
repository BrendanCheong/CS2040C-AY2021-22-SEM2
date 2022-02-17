#include <bits/stdc++.h>
using namespace std;

template <typename T>
class binary_heap {
private:
    vector<T> compact_vector; // the underlying data structure, we will ignore index 0
    int heap_size; // heap_size is not always the same as (int)compact_vector.size()

    // three helper navigation function, written in bit manipulation format to improve runtime speed, all three are fast O(1) functions
    int parent(int i) { return i >> 1; } // i>>1 is the same as i/2
    int left(int i) { return i << 1; } // i<<1 is the same as i*2
    int right(int i) { return (i << 1) + 1; } // (i<<1)+1 is the same as i*2+1

    void shift_up(int i) { // O(log n)
        if (i == 1) return; // at root, do nothing
        if (compact_vector[i] > compact_vector[parent(i)]) { // violate property with parent
            swap(compact_vector[i], compact_vector[parent(i)]); // swap upwards
            shift_up(parent(i)); // recurse, at most O(log n) steps back to the root
        }
    }

    void shift_down(int i) { // O(log n)
        if (i > heap_size) return; // beyond last element, do nothing
        int swap_id = i;
        if ((left(i) <= heap_size) && (compact_vector[i] < compact_vector[left(i)])) // compare with left child, if exists
            swap_id = left(i);
        if ((right(i) <= heap_size) && (compact_vector[swap_id] < compact_vector[right(i)])) // compare with right child, if exists
            swap_id = right(i);
        if (swap_id != i) { // need to swap with the larger of the two children
            swap(compact_vector[i], compact_vector[swap_id]); // swap downwards with the larger of the two children
            shift_down(swap_id); // recurse, at most O(log n) steps to one of the bottom-most leaf
        }
    }

public:
    binary_heap() { // O(1)
        compact_vector.push_back(T()); // remember to set index 0 to be 'dummy'
        heap_size = 0; // an empty Binary Heap
    }

    ~binary_heap() { // O(n)
        compact_vector.clear();
    }

    void push(T x) { // O(log n)
        if (heap_size + 1 >= (int)compact_vector.size()) // O(1)
            compact_vector.push_back(T()); // enlarge the vector by one (internally, vector doubles its size) if needed, to avoid potential RTE below, O(1)
        compact_vector[++heap_size] = x; // the only possible insertion point, O(1)
        shift_up(heap_size); // shift upwards, O(log n) at worst
    }

    void pop() { // O(log n)
        swap(compact_vector[1], compact_vector[heap_size--]); // swap with the last existing leaf, O(1)
        shift_down(1); // fix heap property downwards, O(log n) at worst
    }

    T top() { // O(1)
        return compact_vector[1]; // this is the root
    }

    bool empty() { // O(1)
        return heap_size == 0; // the only condition for an empty compact_vector
    }

    int size() { // O(1)
        assert(heap_size <= (int)compact_vector.size()); // should be true at all times
        return heap_size;
    }
};

int main() {
    cout << "Our own Binary Heap\n";
    binary_heap<int> pq; // this shows that binary (max) heap can be used as an efficient ADT Priority Queue
    cout << pq.empty() << '\n'; // should be 1/true as pq content is {}

    pq.push(5);
    cout << pq.empty() << '\n'; // should be 0/false as pq content is {5 (max)}

    pq.push(2);
    pq.push(7);
    pq.push(3);
    cout << pq.top() << '\n'; pq.pop(); // should be 7 as pq content is {7 (max),5,3,2} -> {5 (max),3,2}

    pq.push(1);
    cout << pq.top() << '\n'; // should be 5 as pq content is {5 (max),3,2,1}
    cout << pq.top() << '\n'; pq.pop(); // should still be 5 as pq content is {5 (max),3,2,1} -> {3 (max),2,1}

    pq.push(8);
    cout << pq.top() << '\n'; pq.pop(); // should be 8 now as pq content is {8 (max),3,2,1} -> {3 (max),2,1}

    cout << "C++ STL version\n";
    priority_queue<int> pq_stl;
    cout << pq_stl.empty() << '\n'; // should be 1/true as pq_stl content is {}

    pq_stl.push(5);
    cout << pq_stl.empty() << '\n'; // should be 0/false as pq_stl content is {5 (max)}

    pq_stl.push(2);
    pq_stl.push(7);
    pq_stl.push(3);
    cout << pq_stl.top() << '\n'; pq_stl.pop(); // should be 7 as pq_stl content is {7 (max),5,3,2} -> {5 (max),3,2}

    pq_stl.push(1);
    cout << pq_stl.top() << '\n'; // should be 5 as pq_stl content is {5 (max),3,2,1}
    cout << pq_stl.top() << '\n'; pq_stl.pop(); // should still be 5 as pq_stl content is {5 (max),3,2,1} -> {3 (max),2,1}

    pq_stl.push(8);
    cout << pq_stl.top() << '\n'; pq_stl.pop(); // should be 8 now as pq_stl content is {8 (max),3,2,1} -> {3 (max),2,1}

    // large random test
    srand(time(NULL));
    binary_heap<int> ours;
    priority_queue<int> theirs;
    assert(ours.empty() && theirs.empty()); // both empty at the start
    for (int i = 0; i < 1000000; ++i) {
        int value = rand();
        ours.push(value), theirs.push(value); // yes you can use comma like this... or just split this into two lines
    }
    assert(!ours.empty() && !theirs.empty()); // both not empty (has 1M entries) by now
    assert(ours.size() == (int)theirs.size()); // heap size should match, note that ours.size() returns int, theirs.size() returns size_t (depends on implementation, may not be really int)
    while (!ours.empty()) {
        assert(ours.top() == theirs.top()); // max value should match
        ours.pop(), theirs.pop();
        assert(ours.size() == (int)theirs.size()); // heap size should match
    }
    assert(ours.empty() && theirs.empty()); // both empty at the end

    return 0;
}