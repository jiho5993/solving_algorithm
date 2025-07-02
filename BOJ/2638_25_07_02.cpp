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
bool arr[101][101];
int cnt[101][101];
bool visited[101][101];
set<pair<int, int> > melt;

bool bfs(int x, int y) {
    bool is_deleted = false;

    memset(cnt, 0, sizeof(cnt));
    memset(visited, 0, sizeof(visited));
    melt.clear();
    queue<pair<int, int> > qp;

    qp.push({x, y});
    visited[x][y] = true;

    while (!qp.empty()) {
        int x = qp.front().first, y = qp.front().second;
        qp.pop();

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (visited[nx][ny]) continue;

            if (arr[nx][ny]) {
                cnt[nx][ny]++;
                if (cnt[nx][ny] >= 2) {
                    melt.insert({nx, ny});
                }
                is_deleted = true;
                continue;
            }

            visited[nx][ny] = true;
            qp.push({nx, ny});
        }
    }

    return is_deleted;
}

void solve() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> arr[i][j];
        }
    }

    int res = 0;
    while (1) {
        int x, y;
        for (int i=0; i<N; i++) {
            bool flag = false;
            for (int j=0; j<M; j++) {
                if (arr[i][j] == 0) {
                    x = i;
                    y = j;
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        
        
        if (bfs(x, y)) {
            for (auto cur: melt) {
                int x = cur.first, y = cur.second;
                arr[x][y] = false;
            }
            res++;
        } else {
            cout << res;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
