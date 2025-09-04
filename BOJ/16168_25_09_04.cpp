#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int V, E;
vector<int> arr[3001];
bool visited[3001][3001];

int dfs(int x, int cnt, bool visited[3001][3001]) {
    for (int n: arr[x]) {
        if (visited[x][n] || visited[n][x]) continue;
        visited[x][n] = visited[n][x] = true;
        return dfs(n, cnt+1, visited);
    }

    return cnt;
}

void solve() {
    cin >> V >> E;
    for (int i=0; i<E; i++) {
        int a, b; cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int i=1; i<=V; i++) {
        memset(visited, 0, sizeof(visited));
        int res = dfs(i, 0, visited);
        if (res == E) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
