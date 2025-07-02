#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int N;
string arr[55];
int res = -1;

bool is_range(int x, int y) {
    return (0 <= x && x < N) && (0 <= y && y < N);
}

int cnt_candy(int d, int x, int y, string cp[55]) {
    int res = 0;

    int nx = x + dx[d];
    int ny = y + dy[d];
    while (is_range(nx, ny) && cp[nx][ny] == cp[x][y]) {
        nx += dx[d];
        ny += dy[d];
        res++;
    }

    return res;
}

void foo(int x, int y) {
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!is_range(nx, ny)) continue;

        string cp[55];
        copy(begin(arr), end(arr), begin(cp));
        swap(cp[nx][ny], cp[x][y]);

        for (int j: {0, 2}) {
            int s = 1;
            s += cnt_candy(j, x, y, cp);
            s += cnt_candy(j+1, x, y, cp);
            res = max(res, s);
        }
    }
}

void solve() {
    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            foo(i, j);
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
