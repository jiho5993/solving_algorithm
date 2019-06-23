#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 1001
int adjmat[MAX_NUM][MAX_NUM];
int N, M, V;
int visit[MAX_NUM];

void dfs(int v) {
    printf("%d ", v);
    visit[v] = 1;
    for(int i=1; i<=N; i++) {
        if(visit[i] == 1 || adjmat[v][i] == 0)
            continue;
        dfs(i);
    }
}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visit[v] = 2;
    while(!q.empty()) {
        v = q.front();
        printf("%d ", q.front());
        q.pop();
        for(int i=1; i<=N; i++) {
            if(visit[i] == 2 || adjmat[v][i] == 0)
                continue;
            q.push(i);
            visit[i] = 2;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int a, b;
    cin >> N >> M >> V;
    for(int i=0; i<M; i++) {
        cin >> a >> b;
        adjmat[a][b] = adjmat[b][a] = 1;
    }
    dfs(V);
    printf("\n");
    bfs(V);

    return 0;
}