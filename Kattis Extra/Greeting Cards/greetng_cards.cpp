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

void printList(vector<pair<ll, ll>>& li) {
    // print out the list
    for (auto it = li.begin(); it != li.end(); it++) {
        cout << "<" << it->first << ", " << it->second << ">" << endl;
    }
}

void printSet(set<pair<ll, ll>>& set) {
    // print out the set
    for (auto it = set.begin(); it != set.end(); it++) {
        cout << "<" << it->first << ", " << it->second << ">" << endl;
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pair<ll, ll>> possible_points = {
        {-2018,0},
        {-1680,-1118},
        {-1680,1118},
        {-1118,-1680},
        {-1118,1680},
        {0,-2018},
        {0,2018},
        {1118,-1680},
        {1118,1680},
        {1680,-1118},
        {1680,1118},
        {2018,0}
    };
    // there are only 12 possible points that when joined together form a circle of radius 2018.
    // so we make sure each Pair(X, Y) has its own set of 12 possible points
    // when we check for another X,Y, check if that set of points exist in the list
    vector<pair<ll, ll>> list;
    set<pair<ll, ll>> s;
    ll N, X, Y;
    ll ans = 0;
    cin >> N;
    for (size_t i = 0; i < N; i++) {
        cin >> X >> Y;
        pair<ll, ll> p = { X, Y };
        list.push_back(p);
        s.insert(p);
    }

    for (auto& pll : list) {
        for (size_t i = 0; i < 12; i++) {
            pair<ll, ll> point = { pll.first + possible_points[i].first, pll.second + possible_points[i].second };
            if (s.count(point))
                ++ans;
        }

    }

    cout << ans / 2 << endl;

    return 0;
}