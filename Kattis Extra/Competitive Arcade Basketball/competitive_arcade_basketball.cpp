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
    ll n, p, m; cin >> n >> p >> m;
    bool winner = false;
    unordered_map<string, ll> players;
    while (n--) {
        string name; cin >> name;
        players[name] = 0;
    }

    for (size_t i = 0; i < m; i++) {
        string player; cin >> player;
        ll points; cin >> points;
        if (players.count(player)) {
            players[player] += points;
            if (players[player] >= p) {
                cout << player << " wins!" << endl;
                players.erase(player);
                winner = true;
            }
            //cout << player << ": " << players[player] << endl;
        }
    }

    if (!winner)
        cout << "No winner!" << endl;

    return 0;
}