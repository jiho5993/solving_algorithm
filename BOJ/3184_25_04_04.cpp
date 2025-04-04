#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int N, M;
string arr[251];
bool visited[251][251];
int res1 = 0, res2 = 0;

void bfs(int a, int b) {
    queue<pair<int, int> > qp;
    qp.push({a, b});
    visited[a][b] = true;

    int o = 0, v = 0;
    while (!qp.empty()) {
        int x = qp.front().first, y = qp.front().second;
        qp.pop();

        if (arr[x][y] == 'o') o++;
        else if (arr[x][y] == 'v') v++;

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (arr[nx][ny] == '#' || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            qp.push({nx, ny});
        }
    }

    debug << a << ' ' << b << " - ";
    debug << o << ' ' << v << '\n';

    if (o > v) res1 += o;
    else res2 += v;
}

void solve() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (arr[i][j] != '#' && !visited[i][j]) {
                bfs(i, j);
            }
        }
    }

    cout << res1 << ' ' << res2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
