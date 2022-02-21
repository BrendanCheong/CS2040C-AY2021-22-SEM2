/**
 * Matric: A0217988E
 * Name: Brendan Cheong Ern Jie
 * Lab: 10
 * TA: Fidella Widjojo
*/
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long int;
template <class T> using binary_tree = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min

template<class T>
void printBinaryTree(binary_tree<T>& bt, ll N) {
    cout << '[';
    for (size_t i = 0; i < N; i++) {
        cout << *bt.find_by_order(i);
        (i == (N - 1)) ? cout << ']' : cout << ", ";
    }
    cout << '\n';
}

struct Test {
    string first;
    ll second;
    char third;
};

template <class T>
struct comp_fx {
    bool operator()(const T& a, const T& b) {
        return a.second > b.second;
    }
};
template <class T>
using test_tree = tree<T, null_type, comp_fx<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    binary_tree<ll> pq_max;

    pq_max.insert(10);
    pq_max.insert(20);
    pq_max.insert(30);
    pq_max.insert(40);
    pq_max.insert(50);
    pq_max.insert(60);
    pq_max.insert(70);
    pq_max.insert(80);
    pq_max.insert(90);
    pq_max.insert(100);

    ll N = pq_max.size();
    printBinaryTree<ll>(pq_max, N);

    cout << "==========================" << '\n';

    pq_max.insert(500);
    pq_max.insert(5);

    // print out pq_max
    printBinaryTree<ll>(pq_max, pq_max.size());

    auto it = pq_max.begin();

    pq_max.erase(it);

    printBinaryTree<ll>(pq_max, pq_max.size());

    // erase based on index
    auto it2 = pq_max.begin();
    it2 = next(it2, 2);

    pq_max.erase(it2);
    printBinaryTree<ll>(pq_max, pq_max.size());

    // erase by finding exact value

    auto it3 = pq_max.find(30);
    pq_max.erase(it3);
    printBinaryTree<ll>(pq_max, pq_max.size());

    // custom binary tree
    struct Test t1 = { "hello", 10, 'a' };
    struct Test t2 = { "world", 20, 'b' };
    struct Test t3 = { "deez", 30, 'c' };
    struct Test t4 = { "nutz", 40, 'd' };

    test_tree<Test> test;

    test.insert(t1);
    test.insert(t2);
    test.insert(t3);
    test.insert(t4);

    for (size_t i = 0; i < test.size(); i++) {
        Test t = *test.find_by_order(i);
        cout << t.first << endl;
    }

    cout << "==========================" << '\n';

    // I can find and erase custom types, based on exact value or a copy of the same values

    struct Test t2_copy = { "world", 20, 'b' };
    auto it4 = test.find(t2_copy);
    test.erase(it4);

    for (size_t i = 0; i < test.size(); i++) {
        Test t = *test.find_by_order(i);
        cout << t.first << endl;
    }

    cout << "==========================" << '\n';

    // to modify, I must erase and insert

    auto it5 = test.find(t3);
    t3.first = "These fine pair of ";
    test.erase(it5);
    test.insert(t3);
    for (size_t i = 0; i < test.size(); i++) {
        Test t = *test.find_by_order(i);
        cout << t.first << endl;
    }


    // printBinaryTreeSpecial<Test>(pq_test, pq_test.size());

    return 0;
}
