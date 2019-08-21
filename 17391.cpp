#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 1e9;
const int MOD = 1000000007;

const int dx[2] = {1, 0};
const int dy[2] = {0, 1};
int n, m, mm=INF;
int MAP[301][301];
int visit[301][301];

struct info {
    int y, x, cnt;
};

void bfs(int y, int x) {
    queue<info> qp;
    qp.push({y, x, 0});
    while(!qp.empty()) {
        int xx = qp.front().x;
        int yy = qp.front().y;
        int cnt = qp.front().cnt;
        visit[yy][xx] = 1;
        qp.pop();
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= MAP[yy][xx]; j++) {
                int nx = xx + dx[i] * j;
                int ny = yy + dy[i] * j;
                if ((1 <= nx && nx <= m) && (1 <= ny && ny <= n) && !visit[ny][nx]) {
                    if (ny == n && nx == m) {
                        mm = min(mm, cnt+1);
                        continue;
                    }
                    visit[ny][nx] = 1;
                    qp.push({ny, nx, cnt+1});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> m;
    for(int i=1; i<n+1; i++)
        for(int j=1; j<m+1; j++)
            cin >> MAP[i][j];
    bfs(1, 1);
    pt(mm);

    return 0;
}