#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int N, E;
int t1, t2;
vector<pair<int, int> > adj[801];
int dist[801][801];

void dij(int st) {
    fill(dist[st], dist[st]+801, 1e9);
    dist[st][st] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, st});

    while (!pq.empty()) {
        int c, v;
        tie(c, v) = pq.top();
        pq.pop();

        if (dist[st][v] < c) continue;

        for (auto i: adj[v]) {
            int n = i.first;
            int nc = c + i.second;
            if (dist[st][n] > nc) {
                dist[st][n] = nc;
                pq.push({nc, n});
            }
        }
    }
}

void solve() {
    cin >> N >> E;
    for (int i=0; i<E; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    cin >> t1 >> t2;

    dij(1);
    dij(t1);
    dij(t2);

    int res1 = dist[1][t1] + dist[t1][t2] + dist[t2][N];
    int res2 = dist[1][t2] + dist[t2][t1] + dist[t1][N];

    int res = min(res1, res2);
    if (res >= 1e9 || res < 0) cout << -1;
    else cout << min(res1, res2);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
