#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int T, A, B;
int res = 0;
bool visited[5000001];

void dfs(int t, bool w) {
    if (t > T) return;

    res = max(res, t);
    visited[t] = true;

    for (int cur: {A, B}) {
        if (t+cur > T) continue;
        if (visited[t+cur]) continue;
        dfs(t+cur, w);
    }
    if (w == false) {
        if (visited[t/2]) return;
        dfs(t/2, true);
    }
}

void solve() {
    cin >> T >> A >> B;
    
    dfs(0, false);

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
