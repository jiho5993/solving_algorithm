#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

#define pii pair<int, int>

int N;
vector<pii> arr[10001];

pii bfs(int st) {
    pii res = {st, 0};

    queue<pii> qp;
    bool visited[10001] = {0,};

    qp.push({st, 0});
    visited[st] = true;

    while (!qp.empty()) {
        int x, c;
        tie(x, c) = qp.front();
        qp.pop();

        if (res.second < c) res = {x, c};

        for (auto i: arr[x]) {
            int n = i.first;
            int nc = i.second + c;
            if (visited[n]) continue;
            visited[n] = true;
            qp.push({n, nc});
        }
    }

    return res;
}

void solve() {
    cin >> N;
    for (int i=0; i<N-1; i++) {
        int a, b, c; cin >> a >> b >> c;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }

    pii v1 = bfs(1);
    cout << bfs(v1.first).second;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
