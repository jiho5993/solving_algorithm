#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()


const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int r, c, sx, sy, ex, ey;
char arr[51][51];
int chk[51][51], wa[51][51];
queue<pair<int, int> > wqp;

void water_bfs() {
    while(!wqp.empty()) {
        int x = wqp.front().second;
        int y = wqp.front().first;
        wqp.pop();
        fr(i, 0, 4) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if((0 <= xx && xx < c) && (0 <= yy && yy < r)) {
                if(wa[yy][xx] == 0 && arr[yy][xx] == '.') {
                    wa[yy][xx] = wa[y][x]+1;
                    wqp.push({yy, xx});
                }
            }
        }
    }
}

void bfs() {
    queue<pair<int, int> > qp;
    qp.push({sx, sy});
    while(!qp.empty()) {
        int x = qp.front().second;
        int y = qp.front().first;
        qp.pop();
        fr(i, 0, 4) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if((0 <= xx && xx < c) && (0 <= yy && yy < r)) {
                if(chk[yy][xx] == 0 && (arr[yy][xx] == '.' || arr[yy][xx] == 'D')) {
                    if(wa[yy][xx] == 0) {
                        chk[yy][xx] = chk[y][x]+1;
                        qp.push({yy, xx});
                    } else if(wa[yy][xx] > chk[y][x]+1) {
                        chk[yy][xx] = chk[y][x]+1;
                        qp.push({yy, xx});
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> r >> c;
    fr(i, 0, r) {
        string s; cin >> s;
        fr(j, 0, c) {
            arr[i][j] = s[j];
            if(s[j] == 'S') sx = i, sy = j;
            else if(s[j] == 'D') ex = i, ey = j;
            else if(s[j] == '*') wqp.push({i, j});
        }
    }
    water_bfs(); // 전처리
    bfs();
    if(chk[ex][ey] != 0) cout << chk[ex][ey];
    else cout << "KAKTUS";

    return 0;
}