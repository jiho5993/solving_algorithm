#include <bits/stdc++.h>
using namespace std;

#define LOCAL_TEST

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int N, M;
vector<int> arr[20001];
int visited[20001];
bool res = true;

void dfs(int x, int prev, bool c) {
    debug << "[" << x << ", " << prev << ", " << c << "] ";
    for (int i=1; i<=N; i++) debug << visited[i] << ' ';
    debug << '\n';

    visited[x] = c;

    for (auto n: arr[x]) {
        if (visited[n] != -1) {
            if (n == prev) continue;
            if (visited[n] == visited[x]) {
                res = false;
                return;
            }
            continue;
        }
        dfs(n, x, !c);
    }
}

void solve() {
    int T; cin >> T;
    while (T--) {
        res = true;
        fill(visited, visited+20001, -1);
        for (int i=1; i<=20001; i++) arr[i].clear();

        cin >> N >> M;
        for (int i=0; i<M; i++) {
            int a, b; cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        for (int i=1; i<=N; i++) {
            if (visited[i] != -1) continue;
            dfs(i, -1, true);
            if (!res) break;
        }
        res ? cout << "YES\n" : cout << "NO\n";

        for (int i=1; i<=N; i++) debug << visited[i] << ' ';
        debug << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
