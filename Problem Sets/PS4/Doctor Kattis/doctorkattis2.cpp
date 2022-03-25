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

struct Cat {
    string name;
    ll infection;
    ll arrival;
};

template <class T>
struct comp {
    bool operator()(const T& first, const T& second) {
        if (first.infection == second.infection)
            return first.arrival < second.arrival; // pick lowest arrival time because we will use index
        else
            return first.infection > second.infection;
    }
};
template <class T> using binary_tree = tree<T, null_type, comp<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string name;
    ll N, infection; cin >> N;
    binary_tree<Cat> pq;
    unordered_map<string, Cat> clinic;
    for (ll i = 0; i < N; i++) {
        ll cmd; cin >> cmd;

        if (cmd == 0) {
            cin >> name >> infection;
            struct Cat kitten = { name, infection, i };
            pq.insert(kitten);
            clinic[name] = kitten;
        }
        else if (cmd == 1) {
            cin >> name >> infection;
            Cat kitten = clinic[name];
            pq.erase(kitten);
            (kitten.infection + infection > 100)
                ? kitten.infection = 100
                : kitten.infection += infection;
            pq.insert(kitten);
            clinic[name] = kitten;
        }
        else if (cmd == 2) {
            cin >> name;
            Cat kitten = clinic[name];
            pq.erase(kitten);
            clinic.erase(name);
        }
        else {
            if (pq.size() > 0) {
                Cat topCat = *pq.find_by_order(0);
                cout << topCat.name << '\n';
            }
            else
                cout << "The clinic is empty" << '\n';
        }
    }

    return 0;
}