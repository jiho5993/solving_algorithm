#include <bits/stdc++.h>
#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define len(a) ((int)(a.length()))
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '
using namespace std;

struct tomato {
    int x, y, z;
    tomato(int zz, int yy, int xx) {
        x = xx;
        y = yy;
        z = zz;
    }
};

bool chk = false;
int m, n, h, cnt=1, z_cnt=0;
int box[101][101][101];
int go[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
queue<tomato> qt;

bool ripen() {
    fr(i, 0, h) {
        fr(j, 0, n) {
            fr(k, 0, m) {
                if(!box[i][j][k])
                    return false;
            }
        }
    }
    return true;
}

void bfs() {
    if(!chk) return;
    while(!qt.empty()) {
        int ss = sz(qt);
        fr(i, 0, ss) {
            int x = qt.front().x;
            int y = qt.front().y;
            int z = qt.front().z;
            qt.pop();
            fr(j, 0, 6) {
                int xx = x + go[j][1];
                int yy = y + go[j][0];
                int zz = z + go[j][2];
                if((0 <= xx && xx < m) && (0 <= yy && yy < n) && (0 <= zz && zz < h) && box[zz][yy][xx] == 0) {
                    box[zz][yy][xx] = 1;
                    z_cnt--;
                    qt.push(tomato(zz, yy, xx));
                }
                if(!z_cnt) return;
            }
        }
        cnt++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> m >> n >> h;
    fr(i, 0, h) { // z
        fr(j, 0, n) { // y
            fr(k, 0, m) { // x
                cin >> box[i][j][k];
                if(box[i][j][k] == 0) {
                    z_cnt++;
                    chk = 1;
                } else if(box[i][j][k] == 1)
                    qt.push(tomato(i, j, k));
            }
        }
    }
    bfs();
    if(chk) ripen() ? pt(cnt) : pt("-1");
    else pt("0");

    return 0;
}