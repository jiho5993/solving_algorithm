#include <bits/stdc++.h>
using namespace std;

int N, M, res = 0;
bool arr[101][101];
bool visited[101];

void dfs(int x) {
    res++;
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
        arr[a][b] = arr[b][a] = true;
    }

    dfs(1);
    cout << res - 1;

    return 0;
}
