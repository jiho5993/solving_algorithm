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

int n, m, big, cnt;
int arr[501][501], visit[501][501];
int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs(int x, int y) {
    queue<pair<int, int> > qp;
    qp.push(mp(x, y));
    visit[x][y] = 1;
    int ss=0;
    while(!qp.empty()) {
        int nx = qp.front().first;
        int ny = qp.front().second;
        qp.pop();
        fr(j, 0, 4) {
            int xx = nx + go[j][0];
            int yy = ny + go[j][1];
            if((0 <= xx && xx < n) && (0 <= yy && yy < m) && arr[xx][yy] && !visit[xx][yy]) {
                visit[xx][yy] = 1;
                qp.push(mp(xx, yy));
            }
        }
        ss++;
    }
    return ss;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n >> m; // 10, 8
    fr(i, 0, n) {
        fr(j, 0, m)
            cin >> arr[i][j];
    }
    fr(i, 0, n) {
        fr(j, 0, m) {
            if(arr[i][j] && !visit[i][j]) {
                cnt++;
                int k = bfs(i, j);
                if(big < k) big = k;
            }
        }
    }
    cout << cnt << '\n' << big;

    return 0;
}