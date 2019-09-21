#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
int mat[1001][1001];
bool visit[1001];

void dfs(int v) {
    visit[v] = true;
    for(int i=1; i<=n; i++) {
        if(mat[v][i] == 1 && !visit[i])
            dfs(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        mat[a][b] = mat[b][a] = 1;
    }
    for(int i=1; i<=n; i++) {
        if(!visit[i]) {
            dfs(i);
            cnt++;
        }
    }
    printf("%d\n", cnt);

    return 0;
}