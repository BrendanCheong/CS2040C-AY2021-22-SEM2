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

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N; cin >> N;
    string name, date;
    ll like_level;
    map<string, tuple<string, ll, string>> people;
    vector<string> ans;

    while (N--) {
        cin >> name >> like_level >> date;
        if (people.count(date) > 0 && like_level > get<1>(people[date])) {
            people[date] = make_tuple(name, like_level, date);
        }
        else if (people.count(date) == 0) {
            people[date] = make_tuple(name, like_level, date);
        }
    }

    for (auto& [k, v] : people) {
        ans.push_back(get<0>(v));
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for_each(ans.begin(), ans.end(), [](string& s) { cout << s << '\n'; });

    return 0;
}
