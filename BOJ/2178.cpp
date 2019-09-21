#include <bits/stdc++.h>
using namespace std;

int n, m;
int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 상, 하, 좌, 우
int maze[101][101];
queue<pair<int, int> > qp;

void bfs() {
    qp.push(make_pair(0, 0));
    pair<int, int> cur;
    int nx, ny;
    while(!qp.empty()) {
        cur = qp.front();
        qp.pop();
        for(int i=0; i<4; i++) {
            nx = cur.second + go[i][0];
            ny = cur.first + go[i][1];
            if((0 <= nx && nx < m) && (0 <= ny && ny < n) && maze[ny][nx] == 1) {
                qp.push(make_pair(ny, nx));
                maze[ny][nx] = maze[cur.first][cur.second] + 1;
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    string s;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<m; j++)
            maze[i][j] = s[j]-'0';
    }
    
    bfs();
    printf("%d\n", maze[n-1][m-1]);

    return 0;
}