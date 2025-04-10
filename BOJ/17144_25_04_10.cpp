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
int R, C, T;
int arr[51][51];
vector<pair<int, int> > p;

bool is_range(int x, int y) {
    return (0 <= x && x < R) && (0 <= y && y < C);
}

void diffusion() {
    int prev[51][51] = {0,};
    memcpy(prev, arr, sizeof(arr));

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            int spread = prev[i][j] / 5;

            int cnt = 0;
            for (int k=0; k<4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (!is_range(nx, ny)) continue;
                if (arr[nx][ny] == -1) continue;
                arr[nx][ny] += spread;
                cnt++;
            }

            arr[i][j] -= (spread * cnt);
        }
    }
}

void air() {
    int prev[51][51];
    memcpy(prev, arr, sizeof(arr));

    int p1 = p[0].first;
    int p2 = p[1].first;

    // top
    for (int i=1; i<C; i++) arr[0][i-1] = prev[0][i];
    for (int i=C-1; i>=2; i--) arr[p1][i] = prev[p1][i-1];
    arr[p1][1] = 0;
    for (int i=0; i<p1; i++) arr[i][C-1] = prev[i+1][C-1];
    for (int i=p1-1; i>=1; i--) arr[i][0] = prev[i-1][0];

    // bottom
    for (int i=1; i<C; i++) arr[R-1][i-1] = prev[R-1][i];
    for (int i=C-1; i>=2; i--) arr[p2][i] = prev[p2][i-1];
    arr[p2][1] = 0;
    for (int i=R-1; i>=p2+1; i--) arr[i][C-1] = prev[i-1][C-1];
    for (int i=p2+1; i<R-1; i++) arr[i][0] = prev[i+1][0];
}

void solve() {
    cin >> R >> C >> T;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == -1) {
                p.push_back({i, j});
            }
        }
    }

    while (T--) {
        diffusion();
        air();
    }

    int res = 0;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (arr[i][j] == -1) continue;
            res += arr[i][j];
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
