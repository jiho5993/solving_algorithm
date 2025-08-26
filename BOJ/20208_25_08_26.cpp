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

int N, M, H;
bool visited[11];
pii home;
vector<pii> milk;
int res = -1;

int dist(pii a, pii b) {
    return abs(a.first-b.first)+abs(a.second-b.second);
}

void dfs(pii cur, int m, int s) {
    if (m >= dist(cur, home)) res = max(res, s);

    for (int i=0; i<milk.size(); i++) {
        if (visited[i]) continue;
        visited[i] = true;
        if (m >= dist(cur, milk[i])) {
            dfs(milk[i], m-dist(cur, milk[i])+H, s+1);
        }
        visited[i] = false;
    }
}

void solve() {
    cin >> N >> M >> H;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int a; cin >> a;
            if (a == 1) home = {i, j};
            if (a == 2) milk.push_back({i, j});
        }
    }

    dfs(home, M, 0);

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
