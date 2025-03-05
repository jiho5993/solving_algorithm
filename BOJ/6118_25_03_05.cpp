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
vector<int> arr[20001];
int dist[20001];

void bfs(int st) {
    queue<pii> qp;
    qp.push({st, 0});
    dist[st] = 0;

    while (!qp.empty()) {
        int x = qp.front().first, d = qp.front().second;
        qp.pop();
        for (auto i: arr[x]) {
            if (dist[i] != -1) continue;
            dist[i] = d + 1;
            qp.push({i, d+1});
        }
    }
}

void solve() {
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    fill(dist, dist+N+1, -1);
    bfs(1);

    int mx = *max_element(dist, dist+N);
    int res = 0;
    bool flag = false;
    for (int i=1; i<=N; i++) {
        if (mx == dist[i]) {
            if (!flag) {
                flag = true;
                cout << i << ' ';
            }
            res++;
        }
    }

    cout << mx << ' ' << res;

    for (int i=1; i<=N; i++) debug << dist[i] << ' ';
    debug << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
