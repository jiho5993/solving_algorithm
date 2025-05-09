#include <bits/stdc++.h>
using namespace std;

#define LOCAL_TEST

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> m;
    for (int i=0; i<players.size(); i++) {
        m.insert({players[i], i});
    }

    for (string calling: callings) {
        int cur = m[calling];
        int prev = cur - 1;
        m[calling] = prev;
        m[players[prev]] = cur;
        swap(players[cur], players[prev]);
    }

    return players;
}

void solve() {
    auto res = solution({"mumu", "soe", "poe", "kai", "mine"}, {"kai", "kai", "mine", "mine"});

    for (auto i: res) cout << i << ' ';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
