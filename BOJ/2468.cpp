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

int n, minNum=101, maxNum=0, ccc=0;
int height[101][101], visit[101][101], s[3001];
int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void init() {
    fr(i, 0, 101)
        fill(visit[i], visit[i]+101, 0);
}

void bfs(int h, int x, int y) {
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
                if((0 <= xx && xx < n) && (0 <= yy && yy < n) && !visit[xx][yy] && height[xx][yy] > h) {
                    qp.push(mp(xx, yy));
                    visit[xx][yy] = 1;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n;
    fr(i, 0, n) {
        fr(j, 0, n) {
            cin >> height[i][j];
            minNum = min(minNum, height[i][j]);
            maxNum = max(maxNum, height[i][j]);
        }
    }
    fr(i, minNum-1, maxNum+1) {
        init();
        fr(j, 0, n) {
            fr(k, 0, n) {
                if(!visit[j][k] && height[j][k] > i) {
                    bfs(i, j, k);
                    s[ccc]++;
                }
            }
        }
        ccc++;
    }
    sort(s, s+ccc);
    pt(s[ccc-1]);

    return 0;
}