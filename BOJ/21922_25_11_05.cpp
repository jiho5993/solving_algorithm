#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr
#define ll long long
#define pii pair<int, int>

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

struct Info {
    int x, y;
    int d; // l=0, r=1, u=2, d=3
};

int N, M;
int arr[2001][2001];
int res = 0;
queue<Info> q;
bool visited[2001][2001][4];

void solve() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                for (int d=0; d<4; d++) {
                    q.push({i, j, d});
                    visited[i][j][d] = true;
                }
                res++;
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().x, y = q.front().y;
        int d = q.front().d;
        q.pop();

        int nx = x + dx[d];
        int ny = y + dy[d];
        if (0 > nx || nx >= N || 0 > ny || ny >= M) continue;
        if (visited[nx][ny][d]) continue;

        bool flag = false;
        for (int i=0; i<4; i++) {
            if (visited[nx][ny][i]) {
                flag = true;
            }
        }
        if (!flag) res++;
        visited[nx][ny][d] = true;

        int cur = arr[nx][ny];
        if (cur == 1) {
            if (d == 0) q.push({nx, ny, 1});
            else if (d == 1) q.push({nx, ny, 0});
            else q.push({nx, ny, d});
        } else if (cur == 2) {
            if (d == 2) q.push({nx, ny, 3});
            else if (d == 3) q.push({nx, ny, 2});
            else q.push({nx, ny, d});
        } else if (cur == 3) {
            if (d == 0) q.push({nx, ny, 3});
            else if (d == 1) q.push({nx, ny, 2});
            else if (d == 2) q.push({nx, ny, 1});
            else q.push({nx, ny, 0});
        } else if (cur == 4) {
            if (d == 0) q.push({nx, ny, 2});
            else if (d == 1) q.push({nx, ny, 3});
            else if (d == 2) q.push({nx, ny, 0});
            else q.push({nx, ny, 1});
        } else {
            q.push({nx, ny, d});
        }
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
