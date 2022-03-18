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
template <class T> using binary_tree = tree<T, null_type, logical_and<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change comparator type of logical_and to custom or greater<T> for PQ_max or less<T> for PQ_min

// print unordered_map of strings
template <class T>
void print_map(unordered_map<string, T>& map_, string& var) {
    for (auto& x : map_) {
        cout << x.first << ": " << x.second << " looking for: " << var << endl;
    }
}

string checkDec(string& variable_, unordered_map<string, string>& parents, unordered_map<string, unordered_map<string, string>>& variable_types, string block_curr) {
    string declared = "";
    string block_ = parents[block_curr];
    while (block_ != "-1") {
        // print_map(variable_types[block_], variable_);
        if (variable_types[block_].count(variable_))
            return variable_types[block_][variable_];
        block_ = parents[block_];
        // cout << "the block: " << block_ << endl;
    }
    return declared;
}

void solve() {
    int n;
    cin >> n;
    unordered_map<string, string> parents;
    unordered_map<string, int> blocks;
    unordered_map<string, unordered_map<string, string>> variable_types; //<block, <variable, type>> 
    string block = "1";
    parents[block] = "-1";
    blocks[block] = 0;
    for (int i = 0; i < n; i++) {
        string s1, s2, s3;
        cin >> s1;
        if (s1 == "{") {
            string new_block = block + "_" + to_string(blocks[block]);
            parents[new_block] = block;
            blocks[block]++;
            block = new_block;
        }
        else if (s1 == "DECLARE") {
            cin >> s2 >> s3;
            if (variable_types[block].count(s2)) {
                cout << "MULTIPLE DECLARATION" << '\n';
                return;
            }
            else
                variable_types[block][s2] = s3;
        }
        else if (s1 == "TYPEOF") {
            cin >> s2;
            if (variable_types[block].count(s2))
                cout << variable_types[block][s2] << '\n';
            else {
                string declared = checkDec(s2, parents, variable_types, block);
                if (declared == "")
                    cout << "UNDECLARED" << '\n';
                else
                    cout << declared << '\n';
            }
        }
        else {
            block = parents[block];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}