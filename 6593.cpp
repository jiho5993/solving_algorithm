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

struct pos {
    int x, y, z, rs;
    pos(int zz, int yy, int xx, int rrss) {
        x = xx;
        y = yy;
        z = zz;
        rs = rrss;
    }
};

struct dest {
    int x, y, z;
    dest(int zz, int yy, int xx) {
        x = xx;
        y = yy;
        z = zz;
    }
};

int l, r, c;
char building[31][31][31];
int visit[31][31][31];
int go[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
queue<pos> q;

void clear() {
    while(!q.empty()) q.pop();
    fr(i, 0, 31) {
        fr(j, 0, 31) {
            fill(building[i][j], building[i][j]+31, 0);
            fill(visit[i][j], visit[i][j]+31, 0);
        }
    }
}

int bfs(dest de) {
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        int rs = q.front().rs;
        q.pop();
        if(x == de.x && y == de.y && z == de.z) return rs;
        if(!visit[z][y][x]) visit[z][y][x] = 1;
        fr(i, 0, 6) {
            int xx = x + go[i][0];
            int yy = y + go[i][1];
            int zz = z + go[i][2];
            if((0 <= xx && xx < c) && (0 <= yy && yy < r) && (0 <= zz && zz < l)) {
                if(building[zz][yy][xx] != '#' && !visit[zz][yy][xx]) {
                    q.push(pos(zz, yy, xx, rs+1));
                    visit[zz][yy][xx] = 1;
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    while(1) {
        clear();
        dest de = dest(0, 0, 0);
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0) break;
        fr(i, 0, l) {
            fr(j, 0, r) {
                string s; cin >> s;
                fr(k, 0, c) {
                    building[i][j][k] = s[k];
                    if(s[k] == 'S') q.push(pos(i, j, k, 0));
                    else if(s[k] == 'E') {de = dest(i, j, k);}
                }
            }
        }
        int rs = bfs(de);
        if(rs == -1) pt("Trapped!");
        else cout << "Escaped in " << rs << " " << "minute(s).\n";
    }

    return 0;
}