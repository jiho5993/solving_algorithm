#include <bits/stdc++.h>
using namespace std;

int N, M;
bool arr[1001][1001];
bool visited[1001];

void dfs(int x) {
    visited[x] = true;

    for (int i=1; i<=N; i++) {
        if (!arr[x][i] || visited[i]) continue;
        dfs(i);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        arr[a][b] = true;
        arr[b][a] = true;
    }

    int res = 0;
    for (int i=1; i<=N; i++) {
        if (visited[i]) continue;
        dfs(i);
        res++;
    }

    cout << res;

    return 0;
}
