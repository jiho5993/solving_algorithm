#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr
#define ll long long
#define pii pair<int, int>

int N;
vector<int> adj[200001];
int dist[200001];

void solve() {
    cin >> N;
    for (int i=1; i<=N; i++) {
        int a; cin >> a;
        adj[a].push_back(i);
    }

    fill(dist, dist+200001, -1);
    queue<int> q;

    q.push(N);
    dist[N] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int n: adj[x]) {
            if (dist[n] == -1) {
                dist[n] = dist[x] + 1;
                q.push(n);
            }
        }
    }

    for (int i=1; i<=N; i++) cout << dist[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
