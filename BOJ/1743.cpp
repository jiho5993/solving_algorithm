#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
bool visit[101][101];
int n, m, k;
int rs=0, arr[101][101];

void bfs(int y, int x) {
    queue<pair<int, int> > qp;
    qp.push({y, x});
    visit[y][x] = 1;
    int cnt=0;
    while(!qp.empty()) {
        int ss = qp.size();
        while(ss--) {
            int y = qp.front().first;
            int x = qp.front().second;
            qp.pop();
            fr(i, 0, 4) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if ((1 <= xx && xx <= m) && (1 <= yy && yy <= n)) {
                    if (!visit[yy][xx] && arr[yy][xx]) {
                        qp.push({yy, xx});
                        visit[yy][xx] = 1;
                    }
                }
            }
            cnt++;
        }
    }
    rs = max(rs, cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> m >> k;
    while(k--) {
        int a, b; cin >> a >> b;
        arr[a][b] = 1;
    }
    fr(i, 1, n+1)
        fr(j, 1, m+1)
            if(arr[i][j] && !visit[i][j])
                bfs(i, j);
    cout << rs;

    return 0;
}