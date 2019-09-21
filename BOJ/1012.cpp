#include <bits/stdc++.h>
using namespace std;

int t, m, n, k;
int cabbage[51][51], visit[51][51];
int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void init() {
    for(int i=0; i<51; i++) {
        memset(cabbage[i], 0, 51*sizeof(int));
        memset(visit[i], 0, 51*sizeof(int));
    }
}

void bfs(int x, int y) {
    queue<pair<int, int> > qp;
    qp.push(make_pair(x, y));
    visit[x][y] = 1;

    while(!qp.empty()) {
        int nx = qp.front().first;
        int ny = qp.front().second;
        qp.pop();
        for(int i=0; i<4; i++) {
            int xx = nx + go[i][1];
            int yy = ny + go[i][0];
            if((0 <= xx && xx < m) && (0 <= yy && yy < n) && cabbage[xx][yy] == 1 && visit[xx][yy] == 0) {
                visit[xx][yy] = 1;
                qp.push(make_pair(xx, yy));
            }
        }
    }
}

int main() {
    
    cin >> t;
    while(t--) {
        init();
        cin >> m >> n >> k;
        int x, y;
        for(int i=0; i<k; i++) {
            cin >> x >> y;
            cabbage[x][y] = 1;
        }
        int cnt=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(cabbage[i][j] == 1 && visit[i][j] == 0) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}