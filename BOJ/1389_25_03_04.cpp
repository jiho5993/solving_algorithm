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
bool arr[101][101];
int dist[101];

int bfs(int st) {
    int ret = 0;
    queue<int> q;
    for (int i=1; i<=N; i++) dist[i] = -1;

    q.push(st);
    dist[st] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        for (int i=1; i<=N; i++) {
            if (!arr[x][i] || dist[i] != -1) continue;
            q.push(i);
            dist[i] = dist[x] + 1;
            ret += dist[i];
        }
    }

    for (int i=1; i<=N; i++) debug << dist[i] << ' ';
    debug << '\n';

    return ret;
}

void solve() {
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        arr[a][b] = arr[b][a] = true;
    }

    int res = 0, mn = 1e4;
    for (int i=1; i<=N; i++) {
        int s = bfs(i);
        if (s < mn) {
            mn = s;
            res = i;
        }
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
