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

void jump(stack<ll>& Stack, ll& ans, ll& max_num, vll& nums, ll& i) {
    if (!Stack.empty()) {
        while (Stack.size() > 0 && nums[i] >= max_num) { // stop at the highest number closest to nums[i]
            // cout << " at idx: " << Stack.top() << " is " << nums[Stack.top()] << " compared with max: " << max_num
            //     << " jump at: " << (max_num - nums[Stack.top()])
            //     << '\n';
            ans = max(ans, max_num - nums[Stack.top()]);
            Stack.pop();
        }
    }
    Stack.push(i);
    max_num = max(max_num, nums[i]);
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N; cin >> N;
    vll nums;
    ll ans = -1;
    ll max_num = -1;
    stack<ll> st1;
    stack<ll> st2;
    if (N <= 2) { // O(1)
        cout << 0 << endl;
        return 0;
    }

    for (size_t i = 0; i < N; i++) {
        ll input; cin >> input;
        nums.push_back(input);
    }

    for (ll i = 0; i < N; i++) {
        jump(st1, ans, max_num, nums, i);
    }
    max_num = -1; // reset max num, if none found automatically max_num will be 0
    for (ll i = N - 1; i >= 0; i--) {
        jump(st2, ans, max_num, nums, i);
    }

    cout << ans << '\n';
    return 0;
}