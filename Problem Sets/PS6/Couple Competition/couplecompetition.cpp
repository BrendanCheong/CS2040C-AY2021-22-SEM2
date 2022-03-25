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
typedef vector<ll> vll;
template <class T> using binary_tree = tree<T, null_type, logical_and<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min

// print out vector
void printVector(vll& v) {
    ll N = v.size();
    cout << '[';
    if (!N) cout << ']';
    for (size_t i = 0; i < N; i++) {
        cout << v[i];
        (i == (N - 1)) ? cout << ']' : cout << ", ";
    }
    cout << '\n';
}

// print a vector of vectors
void printVectorOfVectors(vector<vll>& v) {
    ll N = v.size();
    for (size_t i = 0; i < N; i++) {
        printVector(v[i]);
    }
}

void processAL(vector<vll>& AL, vll& nodes, stack<ll>& Stack, vll& max_num_idx, ll max_num, ll& i, bool check_max) {
    if (nodes[i] == max_num && check_max) // check_max prevents duplicates from iterating second round
        max_num_idx.push_back(i); // just to make sure we know the "sources" for our multi-source BFS
    if (Stack.size() > 0) { // Stack.top() is the previous idx, while i is the current idx
        while (Stack.size() > 0 && nodes[Stack.top()] <= nodes[i]) { // pop until we get to the biggest node from the current nodes[i], if biggest reached then stop
            Stack.pop(); // by popping, we get to the biggest node in the stack from node[i]
        }
        if (Stack.size() > 0) { // if stack empty that means there are no bigger numbers than node[i]
            AL[Stack.top()].push_back(i); // since we popped, we know which is the biggest val node[i] to push the desired i into
            // remember that multi-source BFS needs biggest number to point to i
            // and not small point to big, as we want the BFS to start from the biggest number
            // and branch out to the smaller numbers
        }
    }
    Stack.push(i); // so we know which index is which number
}

void multisourceBFS(vector<vll>& AL, queue<ll>& qu, vll& dist, vector<bool>& visited) {
    while (!qu.empty()) {
        ll k = qu.front();
        qu.pop();

        for (auto& i : AL[k]) {
            if (!visited[i]) {
                // push the adjacent unvisited vertices
                // with distance from current source = this
                // vertex's distance + 1
                qu.push(i);
                dist[i] = dist[k] + 1;
                visited[i] = true;
            }
        }
    }
}

void nearestToMaxNode(vector<vll>& AL, ll num_nodes, vll& max_num_idx, vll& dist, vector<bool>& visited) {
    ll n = max_num_idx.size();
    queue<ll> qu;

    for (size_t i = 0; i < n; i++) {
        qu.push(max_num_idx[i]);
        visited[max_num_idx[i]] = true;
    }

    multisourceBFS(AL, qu, dist, visited);

    // print out the number of nodes in the distance vector
    for (auto& ele : dist) {
        cout << ele << ' ';
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N; cin >> N;
    vll nodes; // contains all the nodes at their indexes
    stack<ll> Stack;
    vector<vll> AL;
    AL.assign(N, vll());
    ll max_num = -1;
    vll max_num_idx;
    vll distance; distance.assign(N, 0); // we store the distances from node to highest value node here
    vector<bool> visited; visited.assign(N, false); // visited nodes are kept track of here
    // 10 2 6 2 4 2 5 12 2 3, 0..9
    // 0  1 2 3 4 5 6 7  8 9
    // jumping backwards, 10 no need jump theres nothing
    // 2 jump to 10, 6 jump to 10, 2 jumps to 6, 4 jumps to 6, 2 jumps to 4
    // basically it will jump to the highest number behind it
    // this gives you [1,2],[],[3,4,6], [], [5] and so on
    // do the exact same algo but jump forwards now

    for (size_t i = 0; i < N; i++) {
        ll num; cin >> num;
        nodes.push_back(num);
        max_num = max(max_num, num);
    }

    // forwards
    for (ll i = 0; i < N; ++i) {
        processAL(AL, nodes, Stack, max_num_idx, max_num, i, true);
    }

    // iterate backwards through N
    for (ll i = N - 1; i >= 0; --i) {
        processAL(AL, nodes, Stack, max_num_idx, max_num, i, false);
    }

    // now to do multi-source BFS
    nearestToMaxNode(AL, N, max_num_idx, distance, visited);

    // cout << max_num << endl;
    // cout << '\n';
    // printVectorOfVectors(AL);
    // printVector(max_num_idx);

    return 0;
}
