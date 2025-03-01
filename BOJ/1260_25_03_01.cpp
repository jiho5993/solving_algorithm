#include <bits/stdc++.h>
using namespace std;

int N, M, V;
bool arr[1001][1001];
bool visited[1001];

void dfs(int x) {
    cout << x << ' ';
    visited[x] = true;

    for (int i=1; i<=N; i++) {
        if (arr[x][i] && !visited[i]) {
            dfs(i);
        }
    }
}

void bfs(int x) {
    queue<int> q;
    visited[x] = true;
    q.push(x);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (int i=1; i<=N; i++) {
            if (arr[cur][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> V;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        arr[a][b] = arr[b][a] = true;
    }

    dfs(V);
    memset(visited, 0, sizeof(bool) * 1001);
    cout << '\n';
    bfs(V);

    return 0;
}
