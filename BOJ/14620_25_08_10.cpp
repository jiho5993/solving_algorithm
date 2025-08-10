#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
int arr[11][11];
bool visited[11][11];
int res = 1e9;

void check_visit(int x, int y, bool flag) {
    visited[x][y] = flag;
    for (int i=0; i<4; i++) {
        visited[x+dx[i]][y+dy[i]] = flag;
    }
}

void dfs(int cnt, int acc) {
    if (cnt == 3) {
        res = min(res, acc);
        return;
    }

    for (int i=1; i<N-1; i++) {
        for (int j=1; j<N-1; j++) {
            bool flag = false;

            int s = arr[i][j];
            for (int k=0; k<4 && !flag; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (visited[nx][ny]) {
                    flag = true;
                    continue;
                }
                s += arr[nx][ny];
            }

            if (flag) continue;

            check_visit(i, j, true);
            dfs(cnt+1, acc+s);
            check_visit(i, j, false);
        }
    }
}

void solve() {
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(0, 0);

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
