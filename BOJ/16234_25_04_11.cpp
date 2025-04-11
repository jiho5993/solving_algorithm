#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

#define pii pair<int, int>

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int N, L, R;
int arr[51][51];
bool visited[51][51];

bool p_move(int x, int y) {
    queue<pii> qp;
    qp.push({x, y});
    visited[x][y] = true;

    int s = 0;
    vector<pii> acc;
    while (!qp.empty()) {
        int x = qp.front().first, y = qp.front().second;
        qp.pop();
        s += arr[x][y];
        acc.push_back({x, y});

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
            
            int diff = abs(arr[x][y] - arr[nx][ny]);
            if (L <= diff && diff <= R) {
                if (visited[nx][ny]) continue;
                visited[nx][ny] = true;
                qp.push({nx, ny});
            }
        }
    }

    if (acc.size() < 2) return false;

    for (auto i: acc) arr[i.first][i.second] = s/acc.size();
    return true;
}

void solve() {
    cin >> N >> L >> R;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }

    int res = 0;
    while (true) {
        memset(visited, 0, sizeof(visited));

        bool flag = false;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (visited[i][j]) continue;
                bool moved = p_move(i, j);
                if (moved) flag = true;
            }
        }

        if (!flag) break;

        res++;
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
