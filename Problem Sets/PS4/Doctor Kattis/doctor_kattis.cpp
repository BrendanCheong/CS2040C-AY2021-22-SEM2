/**
 * Matric: A0217988E
 * Name: Brendan Cheong Ern Jie
 * Lab: 10
 * TA: Fidella Widjojo
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long int;

struct Cat {
    string name;
    ll infection;
    ll arrival;
};

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<string, Cat> clinic;
    string name;
    ll N, infection;
    ll time = 0;
    auto comp = [](Cat& first, Cat& second) {
        if (first.infection == second.infection)
            return first.arrival > second.arrival; // pick lowest arrival time because we will use index
        else
            return first.infection < second.infection;
    };
    priority_queue<Cat, vector<Cat>, decltype(comp)> pq(comp);
    cin >> N;
    for (size_t i = 0; i < N; i++) {
        ll cm; cin >> cm;

        if (cm == 0) {
            cin >> name >> infection; // O(1) creation or O(log C) create entry in map, where C = 200,000
            struct Cat kitten = { name, infection, time };
            ++time;
            clinic[name] = kitten;
            pq.push(kitten); // O(log C)
            // total O(N log C)
        }
        else if (cm == 1) {
            // increment infection level
            // make sure when incrementing, the maximum value of infection does not exceed 100
            cin >> name >> infection;
            (clinic[name].infection + infection > 100)
                ? clinic[name].infection = 100
                : clinic[name].infection += infection;
            pq.push(clinic[name]); // O(log C), push updated cat into the clinic
            // total O(N log (C))
        }
        else if (cm == 2) {
            cin >> name;
            // erase name from the clinic
            clinic.erase(name); // O(log (C)), where C = 200,000
            // total O(N log(C))
        }
        else {
            // find the highest Cat in the clinic
            // pq can have duplicated cats, but one of the duplicated cats will have a higher infection but same arrival time
            // pq can have cats that don't exist in clinic
            while (!pq.empty()) {
                Cat top = pq.top();
                string topCat = top.name;
                // check if topCat is in the map
                if (clinic.find(topCat) != clinic.end() && clinic[topCat].infection == top.infection) { // O(log(C)) find
                    cout << topCat << endl;
                    break;
                }
                else {
                    pq.pop(); // O(log(C)), discard the false value if found
                }
            }
            if (pq.empty())
                cout << "The clinic is empty" << endl;
            // total O(N log(C))
        }
    }

    return 0;
}