#include <bits/stdc++.h>
using namespace std;

int n, m, cnt=0, rs=1;
int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // up, down, left, right
int box[1001][1001], visit[1001][1001];
bool chk = false;
queue<pair<int, int> > qp;

int bfs() {
    int x, y, xx, yy;
    if(!chk) return 0;
    while(!qp.empty()) {
        int len = qp.size();
        for(int j=0; j<len; j++) {
            x = qp.front().second;
            y = qp.front().first;
            qp.pop();
            if(visit[y][x] == 1) continue;
            else visit[y][x] = 1;
            for(int i=0; i<4; i++) {
                xx = x + go[i][0];
                yy = y + go[i][1];
                if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                if(box[yy][xx] == -1) continue;
                if(box[yy][xx] == 0) {
                    qp.push(make_pair(yy, xx));
                    box[yy][xx] = 1;
                    cnt--;
                }
                if(cnt == 0) return rs;
            }
        }
        rs++;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n >> m;
    for(int i=0; i<m; i++) { // y
        for(int j=0; j<n; j++) { // x
            cin >> box[i][j];
            if(box[i][j] == 1)
                qp.push(make_pair(i, j));
            else if(box[i][j] == 0) {
                chk = true;
                cnt++;
            }
        }
    }
    printf("%d\n", bfs());

    return 0;
}