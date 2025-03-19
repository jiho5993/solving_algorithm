#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int N, M;
vector<pair<int, int> > arr[1001];
bool visited[1001];
int res = -1;

void dfs(int x, int e, int d) {
    if (res != -1) return;
    if (x == e) {
        res = d;
        return;
    }

    visited[x] = true;

    for (auto n: arr[x]) {
        int a = n.first, b = n.second;
        if (visited[a]) continue;
        dfs(a, e, d+b);
    }
}

void solve() {
    cin >> N >> M;
    for (int i=0; i<N-1; i++) {
        int a, b, c; cin >> a >> b >> c;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }

    while (M--) {
        memset(visited, 0, sizeof(bool) * 1001);
        int a, b; cin >> a >> b;
        res = -1;
        dfs(a, b, 0);
        cout << res << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
