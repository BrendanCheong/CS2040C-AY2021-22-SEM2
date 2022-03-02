#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long int;
template <class T> using binary_tree = tree<T, null_type, logical_and<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min

struct Worker {
    pair<ll, ll> work;
    ll current_annoyance;
    ll current_level;
};

ll calc(pair<ll, ll> worker, ll level) {
    return worker.first + (level * worker.second);
}

void toString(Worker& worker) {
    cout << "I choose Worker: "
        << worker.work.first
        << " "
        << worker.work.second
        << " at current annoyance: " << worker.current_annoyance
        << " at current level: " << worker.current_level
        << " and future annyoance: " << calc(worker.work, worker.current_level + 1)
        << '\n';
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll h, c; cin >> h >> c;
    // have a PQ with the current level of annyoance at the moment
    // have a map with the all the current annoyance level
    /**
     * pair<ll, ll> start, increment
     * ll current annoyance
     * ll current level
    */
    ll highest_init_annoyance = 0;
    map<ll, Worker> workers;
    auto comp = [](Worker& w1, Worker& w2) {
        ll future1 = calc(w1.work, w1.current_level + 1);
        ll future2 = calc(w2.work, w2.current_level + 1);
        if (future1 == future2)
            return w1.work.first > w2.work.first; // pick lowest starting
        else
            return future1 > future2; // pick lowest future
    };
    std::priority_queue<Worker, vector<Worker>, decltype(comp)> pq(comp);
    while (c--) {
        ll w, a; cin >> w >> a;
        highest_init_annoyance = max(highest_init_annoyance, w);
        struct Worker worker = { {w, a}, a, 0 };
        pq.push(worker);
    }

    while (h--) {
        Worker worker = pq.top();
        // toString(worker);
        pq.pop();
        worker.current_annoyance = calc(worker.work, worker.current_level + 1);
        worker.current_level++;
        pq.push(worker);
        highest_init_annoyance = max(highest_init_annoyance, worker.current_annoyance);
    }

    cout << highest_init_annoyance << '\n';

    return 0;
}