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
template <class T> using binary_tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min
// in this case doesn't matter if greater<T> or less<T>, as long as it does not allow duplicates (not multiset)

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll cmd, gender;
    string name;
    string lower, upper;
    const ll MALE = 1;
    const ll FEMALE = 2;
    unordered_map<string, ll> babies; // use unordered_map since we don't need deletion
    binary_tree<string> male;
    binary_tree<string> female;
    while (true) {
        cin >> cmd;
        switch (cmd) {
        case(1):
            cin >> name >> gender;
            // insert into correct order_stats_tree according to gender
            (gender == MALE)
                ? male.insert(name)
                : female.insert(name);
            // each unique baby must know its gender
            babies[name] = gender;
            break;
        case(2):
            cin >> name;
            // delete name from correct order_stats_tree according to gender
            (babies[name] == MALE)
                ? male.erase(name)
                : female.erase(name);
            break;
        case(3):
            cin >> lower >> upper >> gender;
            // order of key are all O(log N) operations
            // max total is O(4 log N) here
            // order of key is like your upper bound and lower bound, accept that in augmented trees
            // you can count the number of elements before it
            // similar to rank as seen from prof Alan's lecture on augmented trees
            if (gender == MALE)
                cout << male.order_of_key(upper) - male.order_of_key(lower) << '\n';
            else if (gender == FEMALE)
                cout << female.order_of_key(upper) - female.order_of_key(lower) << '\n';
            else {
                cout << (male.order_of_key(upper) - male.order_of_key(lower)) +
                    (female.order_of_key(upper) - female.order_of_key(lower)) << '\n';
            }
            break;
        case(0):
            return 0;
        }
    }

    return 0;
}
