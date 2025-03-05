#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int N, M;
vector<int> arr[10001];
// bool arr[10001][10001];
bool visited[10001];
int dist[10001], mx_dist = -1;

void dfs(int x) {
    visited[x] = true;
    dist[x]++;
    mx_dist = max(mx_dist, dist[x]);
    
    for (auto i: arr[x]) {
        if (visited[i]) continue;
        dfs(i);
    }
}

void solve() {
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        arr[a].push_back(b);
    }

    for (int i=1; i<=N; i++) {
        memset(visited, 0, sizeof(bool) * 10001);
        dfs(i);
    }

    for (int i=1; i<=N; i++) {
        if (mx_dist == dist[i]) {
            cout << i << ' ';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
