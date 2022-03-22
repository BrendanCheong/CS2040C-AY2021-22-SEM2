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
typedef pair<string, ll> player;

template <class T>
struct comp_fx {
    bool operator()(const T& a, const T& b) {
        if (a.second == b.second) return a.first < b.first; // pick the lowest name
        return a.second > b.second; // pick the highest number
    }
};

template <class T> using AVL = tree<T, null_type, comp_fx<T>, rb_tree_tag, tree_order_statistics_node_update>;

// print out AVL
template<class T>
void printAVL(AVL<T>& bt) {
    ll N = bt.size();
    cout << '[';
    for (size_t i = 0; i < N; i++) {
        player play = *bt.find_by_order(i);
        cout << play.first;
        (i == (N - 1)) ? cout << ']' : cout << ", ";
    }
    cout << '\n';
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N; cin >> N;
    string name;
    ll s1, s2, s3;
    AVL<pair<string, ll>> team1;
    AVL<pair<string, ll>> team2;
    AVL<pair<string, ll>> team3;
    unordered_map<string, tuple<ll, ll, ll>> people;
    people.reserve(N + 100);

    while (N--) {
        cin >> name >> s1 >> s2 >> s3;
        team1.insert(make_pair(name, s1));
        team2.insert(make_pair(name, s2));
        team3.insert(make_pair(name, s3));
        people[name] = { s1, s2, s3 };
    }

    while (team1.size() > 0 && team2.size() > 0 && team3.size() > 0) {
        set<string> names;

        // now I have to deal with duplicated names
        // first find the first player, then erase from the rest of the teams
        if (team1.size() > 0) {
            player p1 = *team1.find_by_order(0);
            // cout << p1.first << " picked" << endl;
            team1.erase({ p1.first, p1.second });
            team2.erase({ p1.first, get<1>(people[p1.first]) });
            team3.erase({ p1.first, get<2>(people[p1.first]) });

            names.insert(p1.first);
        }

        if (team2.size() > 0) {
            player p2 = *team2.find_by_order(0);
            // cout << p2.first << " picked" << endl;
            team2.erase({ p2.first, p2.second });
            team1.erase({ p2.first, get<0>(people[p2.first]) });
            team3.erase({ p2.first, get<2>(people[p2.first]) });

            names.insert(p2.first);
        }

        if (team3.size() > 0) {
            player p3 = *team3.find_by_order(0);
            // cout << p3.first << " picked " << p3.second << endl;
            team3.erase({ p3.first, p3.second });
            team1.erase({ p3.first, get<0>(people[p3.first]) });
            team2.erase({ p3.first, get<1>(people[p3.first]) });

            names.insert(p3.first);
        }

        // printAVL(team1);
        // printAVL(team2);
        // printAVL(team3);

        if (names.size() == 3) {
            for_each(names.begin(), names.end(), [](string s) { cout << s << ' '; });
            cout << '\n';
        }
        else {
            return 0;
        }
    }

    return 0;
}
