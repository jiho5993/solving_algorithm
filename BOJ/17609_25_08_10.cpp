#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

string s;
int res = 2;

void dfs(int l, int r,  bool flag) {
    if (l >= r) {
        if (flag) res = 1;
        else res = 0;
        return;
    }

    if (s[l] == s[r]) dfs(l+1, r-1, flag);
    else {
        if (flag) {
            return;
        }

        dfs(l, r-1, true);
        dfs(l+1, r, true);
    }
}

void solve() {
    int T; cin >> T;
    while (T--) {
        res = 2;
        cin >> s;

        dfs(0, s.size()-1, false);
        cout << res << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
