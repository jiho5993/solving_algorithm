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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int arr[10][10];
int st[2];
bool res = false;

void dfs(int x, int y, int mv, int cnt) {
    if (mv > 3 || res) return;
    if (cnt >= 2) {
        res = true;
        return;
    }
    
    int tmp = arr[x][y];
    arr[x][y] = -1;
    
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 > nx || nx >= 5 || 0 > ny || ny >= 5) continue;
        if (arr[nx][ny] == -1) continue;

        dfs(nx, ny, mv+1, cnt+(arr[nx][ny] == 1));
    }
    arr[x][y] = tmp;
}

void solve() {
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> st[0] >> st[1];

    dfs(st[0], st[1], 0, 0);
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
