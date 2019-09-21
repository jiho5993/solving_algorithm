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

#define MX 301

int n, m, year=0;
int height[MX][MX], visit[MX][MX];
int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void init() {
    fr(i, 0, MX)
        fill(visit[i], visit[i]+MX, 0);
}

void melt() {
    int c_height[MX][MX];
    fr(i, 0, n) {
        fr(j, 0, m)
            c_height[i][j] = height[i][j];
    }
    fr(i, 0, n) {
        fr(j, 0, m) {
            if(c_height[i][j] > 0) {
                int cnt=0;
                fr(k, 0, 4) {
                    int xx = j + go[k][1];
                    int yy = i + go[k][0];
                    if((0 <= xx && xx < m) && (0 <= yy && yy < n) && !c_height[yy][xx])
                        cnt++;
                }
                height[i][j] = max(0, c_height[i][j] - cnt);
            }
        }
    }
}

void bfs(int y, int x) {
    queue<pair<int, int> > qp;
    qp.push(mp(y, x));
    visit[y][x] = 1;
    while(!qp.empty()) {
        int x = qp.front().second;
        int y = qp.front().first;
        qp.pop();
        fr(i, 0, 4) {
            int xx = x + go[i][1];
            int yy = y + go[i][0];
            if((0 <= xx && xx < m) && (0 <= yy && yy < n) && height[yy][xx] > 0 && !visit[yy][xx]) {
                qp.push(mp(yy, xx));
                visit[yy][xx] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n >> m;
    fr(i, 0, n) {
        fr(j, 0, m)
            cin >> height[i][j];
    }
    while(1) {
        init();
        int cnt=0;
        fr(i, 0, n) {
            fr(j, 0, m) {
                if(height[i][j] > 0 && !visit[i][j]){
                    cnt++;
                    bfs(i, j);
                }
            }
        }
        if(cnt > 1) break;
        if(cnt == 0) {
            year = 0;
            break;
        }
        melt();
        year++;
    }
    pt(year);

    return 0;
}