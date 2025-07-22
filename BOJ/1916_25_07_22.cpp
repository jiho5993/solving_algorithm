#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

vector<pair<int, int> > arr[1001];
int dist[1001];

void dij(int st) {
    priority_queue<pair<int, int> > pq;
    fill(dist, dist+1001, 1e9);
    
    pq.push({0, st});
    dist[st] = 0;

    while (!pq.empty()) {
        int c, p;
        tie(c, p) = pq.top();
        pq.pop();

        if (dist[p] < c) continue;

        for (auto i: arr[p]) {
            int nc = c + i.second;
            int np = i.first;
            if (dist[np] > nc) {
                dist[np] = nc;
                pq.push({nc, np});
            }
        }
    }
}

void solve() {
    int N, M; cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b, c; cin >> a >> b >> c;
        arr[a].push_back({b, c});
    }
    int st, en; cin >> st >> en;
    dij(st);

    cout << dist[en];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
