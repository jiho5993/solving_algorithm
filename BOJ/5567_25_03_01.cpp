#include <bits/stdc++.h>
using namespace std;

int N, M, res = 0;
bool arr[501][501];
bool visited[501];

void bfs(int st) {
    queue<pair<int, int> > qp;
    qp.push({st, 0});
    visited[st] = true;

    while (!qp.empty()) {
        int x = qp.front().first, d = qp.front().second;
        qp.pop();
        if (d > 2) continue;
        res++;
        for (int i=1; i<=N; i++) {
            if (!arr[x][i] || visited[i]) continue;
            qp.push({i, d+1});
            visited[i] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        arr[a][b] = arr[b][a] = true;
    }

    bfs(1);
    cout << res - 1;

    return 0;
}
