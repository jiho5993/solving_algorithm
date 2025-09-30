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

int dx[][4] = {
    {0, 0, 0, 0},
    {0, 1, 2, 3},

    {0, 0, 1, 1},
    {0, 1, 1, 2},

    {0, 0, 0, 1},
    {0, 1, 2, 2},
    {0, 1, 1, 1},
    {0, 0, 1, 2},

    {0, 0, 0, 1},
    {0, 1, 2, 1},
    {0, 1, 1, 1},
    {0, 1, 2, 1},

    {0, 0, 1, 1},
};
int dy[][4] = {
    {0, 1, 2, 3},
    {0, 0, 0, 0},

    {0, 1, 1, 2},
    {0, 0, -1, -1},

    {0, 1, 2, 2},
    {0, 0, 0, -1},
    {0, 0, 1, 2},
    {0, 1, 0, 0},

    {0, 1, 2, 1},
    {0, 0, 0, -1},
    {0, -1, 0, 1},
    {0, 0, 0, 1},

    {0, 1, 0, 1},
};

int N;
int arr[101][101];

bool is_range(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}

int foo() {
    int res = -1e9;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<13; k++) {
                int s = 0, l = 0;
                for (; l<4; l++) {
                    int nx = i + dx[k][l];
                    int ny = j + dy[k][l];
                    if (!is_range(nx, ny)) break;
                    s += arr[nx][ny];
                }
                if (l != 4) continue;
                res = max(res, s);
            }
        }
    }

    return res;
}

void solve() {
    for (int t=1; ; t++) {
        memset(arr, 0, sizeof(arr));

        cin >> N;
        if (N == 0) return;

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                cin >> arr[i][j];
            }
        }

        cout << t << ". " << foo() << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
