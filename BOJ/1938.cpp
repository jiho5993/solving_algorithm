#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

struct info {
    int x, y, cnt;
    bool shp;
};

// false일때 누워있음, true일때 서있음
const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
int n;
char arr[51][51];
bool visit[51][51][2], B_shape, E_shape;
pair<int, int> B, E, BBB[3], EEE[3];

bool chk_shp(pair<int, int> shp[3]) {
    if(shp[0].first == shp[1].first && shp[1].first == shp[2].first)
        return false;
    else return true;
}

bool T(int x, int y, bool flag) {
    if(!flag) {
        for(int i=0; i<8; i++) {
            if(i == 2 || i == 3) continue;
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx < 0 || xx >= n || yy < 0 || yy >= n) return false;
            if(arr[xx][yy] == '1') return false;
        }
    } else {
        for(int i=0; i<8; i++) {
            if(i == 0 || i == 1) continue;
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx < 0 || xx >= n || yy < 0 || yy >= n) return false;
            if(arr[xx][yy] == '1') return false;
        }
    }
    return true;
}

int bfs(int x, int y) {
    queue<info> qp;
    qp.push({x, y, 0, B_shape});
    visit[x][y][B_shape] = 1;
    while(!qp.empty()) {
        x = qp.front().x;
        y = qp.front().y;
        int cnt = qp.front().cnt;
        bool shp = qp.front().shp;
        qp.pop();
        if(x == E.first && y == E.second) return cnt;
        int xx, yy, nx, ny;
        if(!shp) {
            xx = x-1;
            yy = y;
            if(xx >= 0) {
                if(!visit[xx][yy][shp]) {
                    if(arr[xx][yy] == '0' && arr[xx][yy-1] == '0' && arr[xx][yy+1] == '0') {
                        visit[xx][yy][shp] = 1;
                        qp.push({xx, yy, cnt+1, shp});
                    }
                }
            }
            xx = x + 1;
            yy = y;
            if(xx < n) {
                if(!visit[xx][yy][shp]) {
                    if(arr[xx][yy] == '0' && arr[xx][yy-1] == '0' && arr[xx][yy+1] == '0') {
                        visit[xx][yy][shp] = 1;
                        qp.push({xx, yy, cnt+1, shp});
                    }
                }
            }
            xx = x;
            yy = y - 1;
            ny = y - 2;
            if(ny >= 0) {
                if(!visit[xx][yy][shp]) {
                    if(arr[xx][ny] == '0') {
                        visit[xx][yy][shp] = 1;
                        qp.push({xx, yy, cnt+1, shp});
                    }
                }
            }
            xx = x;
            yy = y+1;
            ny = y+2;
            if(ny < n) {
                if(!visit[xx][yy][shp]) {
                    if(arr[xx][ny] == '0') {
                        visit[xx][yy][shp] = 1;
                        qp.push({xx, yy, cnt+1, shp});
                    }
                }
            }
            if(T(x, y, shp)) {
                if(!visit[x][y][1]) {
                    visit[x][y][1] = 1;
                    qp.push({x, y, cnt+1, 1});
                }
            }
        } else {
            xx = x-1;
            nx = x-2;
            yy = y;
            if(nx >= 0) {
                if(!visit[xx][yy][shp]) {
                    if(arr[nx][yy] == '0') {
                        visit[xx][yy][shp] = 1;
                        qp.push({xx, yy, cnt+1, shp});
                    }
                }
            }
            xx = x+1;
            nx = x+2;
            yy = y;
            if(nx < n) {
                if(!visit[xx][yy][shp]) {
                    if(arr[nx][yy] == '0') {
                        visit[xx][yy][shp] = 1;
                        qp.push({xx, yy, cnt+1, shp});
                    }
                }
            }
            xx = x;
            yy = y-1;
            if(yy >= 0) {
                if(!visit[xx][yy][shp]) {
                    if(arr[xx][yy] == '0' && arr[xx-1][yy] == '0' && arr[xx+1][yy] == '0') {
                        visit[xx][yy][shp] = 1;
                        qp.push({xx, yy, cnt+1, shp});
                    }
                }
            }
            xx = x;
            yy = y+1;
            if(yy < n) {
                if(!visit[xx][yy][shp]) {
                    if(arr[xx][yy] == '0' && arr[xx-1][yy] == '0' && arr[xx+1][yy] == '0') {
                        visit[xx][yy][shp] = 1;
                        qp.push({xx, yy, cnt+1, shp});
                    }
                }
            }
            if(T(x, y, shp)) {
                if(!visit[x][y][0]) {
                    visit[x][y][0] = 1;
                    qp.push({x, y, cnt+1, 0});
                }
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int B_idx=0, E_idx=0;
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        for(int j=0; j<n; j++) {
            arr[i][j] = s[j];
            if(s[j] == 'B') {
                arr[i][j] = '0';
                BBB[B_idx++] = {i, j};
            } else if(s[j] == 'E') {
                arr[i][j] = '0';
                EEE[E_idx++] = {i, j};
            }
        }
    }
    B = BBB[1], E = EEE[1];

    B_shape = chk_shp(BBB);
    E_shape = chk_shp(EEE);

    cout << bfs(B.first, B.second);

    return 0;
}