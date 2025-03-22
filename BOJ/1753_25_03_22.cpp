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

int N, M, K;
vector<pair<int, int> > arr[20001];
vector<int> dist(20001, 1e9);

void dij(int st) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, st});
    dist[st] = 0;

    while (!pq.empty()) {
        int d = pq.top().first, x = pq.top().second;
        pq.pop();
        if (dist[x] != d) continue;
        for (auto i: arr[x]) {
            int n = i.first, nd = i.second;
            if (dist[n] <= dist[x] + nd) continue;
            dist[n] = dist[x] + nd;
            pq.push({dist[n], n});
        }
    }
}

void solve() {
    cin >> N >> M >> K;
    for (int i=0; i<M; i++) {
        int a, b, c; cin >> a >> b >> c;
        arr[a].push_back({b, c});
    }

    dij(K);

    for (int i=1; i<=N; i++) {
        if (dist[i] == 1e9) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
