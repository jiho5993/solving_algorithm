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
int N, M;
int arr[21][21];
bool isused[30];

int res = 0;

void dfs(int x, int y, int cnt) {
    res = max(res, cnt);

    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (isused[arr[nx][ny]]) continue;

        int cur = arr[nx][ny];
        isused[cur] = true;
        dfs(nx, ny, cnt+1);
        isused[cur] = false;
    }
}

void solve() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        string s; cin >> s;
        for (int j=0; j<M; j++) arr[i][j] = s[j]-'A';
    }

    isused[arr[0][0]] = true;
    dfs(0, 0, 1);

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
