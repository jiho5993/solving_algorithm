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

const int INF = 2147483648;
const int MOD = 1000000007;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int MAP[505][505], visit[505][505];
int m, n;

int dfs(int y, int x) {
    if(y == 0 && x == 0) return 1;
    if(visit[y][x] == -1) {
        visit[y][x] = 0;
        fr(i, 0, 4) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if((0 <= xx && xx < n) && (0 <= yy && yy < m)) {
                if(MAP[yy][xx] > MAP[y][x])
                    visit[y][x] += dfs(yy, xx);
            }
        }
    }
    return visit[y][x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> m >> n;
    fr(i, 0, m)
        fr(j, 0, n) {
            cin >> MAP[i][j];
            visit[i][j] = -1;
        }
    pt(dfs(m-1, n-1));

    return 0;
}