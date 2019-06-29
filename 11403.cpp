#include <bits/stdc++.h>
using namespace std;

int n, mat[101][101], visit[101][101];

void dfs(int node, int x) {
    mat[node][x] = 1;
    visit[node][x] = 1;
    for(int i=0; i<n; i++) {
        if(!visit[node][i] && mat[x][i])
            dfs(node, i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            cin >> mat[i][j];
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(mat[i][j] && !visit[i][j])
                dfs(i, j);
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) 
            printf("%d ", visit[i][j]);
        printf("\n");
    }

    return 0;
}
