#include <bits/stdc++.h>
using namespace std;

#define LOCAL_TEST

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

#define pii pair<int, int>

int N, M;
vector<pii> h, c;
int res = 1e9;

void dfs(int idx, vector<pii> cur) {
    if (cur.size() == M) {
        int s = 0;
        for (pii a: h) {
            int tmp = 1e9;
            for (pii b: cur) {
                int dx = abs(b.first - a.first);
                int dy = abs(b.second - a.second);
                tmp = min(tmp, dx + dy);
            }
            s += tmp;
        }
        res = min(s, res);
        return;
    }
    if (idx >= c.size()) {
        return;
    }

    for (int i=idx; i<c.size(); i++) {
        cur.push_back(c[i]);
        dfs(i+1, cur);
        cur.pop_back();
    }
}

void solve() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int a; cin >> a;
            if (a == 1) h.push_back({i, j});
            else if (a == 2) c.push_back({i, j});
        }
    }

    dfs(0, vector<pii>());

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
