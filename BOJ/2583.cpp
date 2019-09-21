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

int m, n, k, cnt=0;
int a[101][101], visit[101][101], ar[10001];
int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs(int x, int y, int idx) {
    queue<pair<int, int> > qp;
    qp.push(mp(x, y));
    visit[x][y] = 1;
    while(!qp.empty()) {
        int ss = sz(qp);
        fr(i, 0, ss) {
            int nx = qp.front().first;
            int ny = qp.front().second;
            qp.pop();
            fr(j, 0, 4) {
                int xx = nx + go[j][1];
                int yy = ny + go[j][0];
                if((0 <= xx && xx < m) && (0 <= yy && yy < n) && !visit[xx][yy] && !a[xx][yy]) {
                    qp.push(mp(xx, yy));
                    visit[xx][yy] = 1;
                    ar[idx]++;
                }
            }
        }
    }
    ar[idx]++;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int q, w, e, r;
    cin >> m >> n >> k;
    fr(i, 0, k) {
        cin >> q >> w >> e >> r;
        fr(pp, w, r) {
            fr(j, q, e)
                a[pp][j] = 1;
        }
    }
    fr(i, 0, m) { // i = x = xx = nx
        fr(j, 0, n) { // j = y = yy = ny
            if(!a[i][j] && !visit[i][j])
                bfs(i, j, cnt++);
        }
    }
    sort(ar, ar+cnt);
    pt(cnt);
    fr(i, 0, cnt) pt1(ar[i]);

    return 0;
}