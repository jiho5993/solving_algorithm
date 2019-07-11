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

int n, t_cnt, f_cnt;
int arr[101][101], visit[101][101];
int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs(int x, int y, int val) {
    queue<pair<int, int> > qp;
    qp.push(mp(x, y));
    visit[x][y] = 1;
    if(arr[x][y] == 0) arr[x][y] = 1;
    while(!qp.empty()) {
        int ss = sz(qp);
        fr(i, 0, ss) {
            int xx = qp.front().first;
            int yy = qp.front().second;
            qp.pop();
            fr(j, 0, 4) {
                int nx = xx + go[j][1];
                int ny = yy + go[j][0];
                if((0 <= nx && nx < n) && (0 <= ny && ny < n) && !visit[nx][ny] && arr[nx][ny] == val) {
                    visit[nx][ny] = 1;
                    qp.push(mp(nx, ny));
                    if(arr[nx][ny] == 0) arr[nx][ny] = 1;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n;
    fr(i, 0, n) {
        string s; cin >> s;
        fr(j, 0, n) {
            if(s[j] == 'R') arr[i][j] = 0;
            else if(s[j] == 'G') arr[i][j] = 1;
            else arr[i][j] = 2;
        }
    }
    fr(i, 0, n) {
        fr(j, 0, n) {
            if(!visit[i][j]) {
                bfs(i, j, arr[i][j]);
                t_cnt++;
            }
        }
    }
    fr(i, 0, n) fill(visit[i], visit[i]+101, 0);
    fr(i, 0, n) {
        fr(j, 0, n) {
            if(!visit[i][j]) {
                bfs(i, j, arr[i][j]);
                f_cnt++;
            }
        }
    }
    pt2(t_cnt, f_cnt);

    return 0;
}