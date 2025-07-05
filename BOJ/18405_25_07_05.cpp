#include <bits/stdc++.h>
using namespace std;

#define LOCAL_TEST

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, K;
int S, X, Y;
int arr[201][201];
queue<pair<int, int> > qp[1001];

void solve() {
    cin >> N >> K;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] != 0) {
                qp[arr[i][j]].push({i, j});
            }
        }
    }
    cin >> S >> X >> Y;

    while (S--) {
        for (int v=1; v<=K; v++) {
            int sz = qp[v].size();
            for (int i=0; i<sz; i++) {
                int x = qp[v].front().first, y = qp[v].front().second;
                qp[v].pop();

                for (int d=0; d<4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
                    if (arr[nx][ny] != 0) continue;
                    arr[nx][ny] = v;
                    qp[v].push({nx, ny});
                }
            }
        }
    }

    cout << arr[X-1][Y-1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
