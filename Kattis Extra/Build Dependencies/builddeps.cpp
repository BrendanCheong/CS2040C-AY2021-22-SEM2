#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
/**
 * I must use DFS algorithm to solve this question
*/
// !NOTE: string hashing is very slow O(K + alpha), K being length of string 
unordered_map<string, vs> AL; // yes, you can do this, and this is very similar to Hash Table, Separate Chaining
unordered_set<string> vis; // input visited vertexes here for fast O(1+alpha) query
vector<string> ans;

void dfs(string u) {
    vis.insert(u);
    for (auto& v : AL[u]) {
        if (!vis.count(v)) { // I haven't go to v
            dfs(v);
        }
    }
    // postorder DFS, once visited u and all its neighbours, I process vertex u
    ans.push_back(u); // input the vistied vertexes into the ans array

}

void iterative_dfs(string u) {
    stack<string> st;
    st.push(u);
    while (!st.empty()) {
        string v = st.top(); st.pop();
        if (vis.count(v)) continue;
        vis.insert(v);
        for (auto& w : AL[v]) {
            if (!vis.count(w)) {
                st.push(w);
            }
        }
        ans.push_back(v);
    }
}

void iterative_bfs(string u) {
    queue<string> q;
    q.push(u);
    while (!q.empty()) {
        string v = q.front(); q.pop();
        if (vis.count(v)) continue;
        vis.insert(v);
        for (auto& w : AL[v]) {
            if (!vis.count(w)) {
                q.push(w);
            }
        }
        ans.push_back(v);
    }
}

int main() {
    string line, file;
    int n; cin >> n; getline(cin, line); // if you don't do this, you will read '\n' after n (int) is read
    AL.reserve(200000);
    vis.reserve(200000);
    AL.clear();
    for (int i = 0; i < n; ++i) {
        string line; getline(cin, line);
        stringstream ss(line); // study stringstream if you are not aware of this before, we need it to tokenize/separate the input line based on ' ' (default separator)
        string file; ss >> file; file.pop_back(); // I don't want the :
        string dep;
        while (ss >> dep) // read all the dependencies
            AL[dep].push_back(file); // yes, we can just do this :)
    }
    getline(cin, file); // the modified file

    vis.clear();
    dfs(file);

    // print the vector of strings ans in reverse
    for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
        cout << *it << '\n';
    }

    return 0;
}
