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
int R, C, N;
int arr[201][201];

void solve() {
    cin >> R >> C >> N;
    for (int i=0; i<R; i++) {
        string s; cin >> s;
        for (int j=0; j<C; j++) {
            if (s[j] == '.') arr[i][j] = 0;
            else arr[i][j] = 3;
        }
    }

    for (int t=2; t<=N; t++) {
        if (t&1) {
            int cp[201][201];
            memcpy(cp, arr, sizeof(arr));
            for (int i=0; i<R; i++) {
                for (int j=0; j<C; j++) {
                    if (cp[i][j] == t) {
                        arr[i][j] = 0;
                        for (int k=0; k<4; k++) {
                            int nx = i + dx[k];
                            int ny = j + dy[k];
                            if (0 > nx || nx >= R || 0 > ny || ny >= C) continue;
                            arr[nx][ny] = 0;
                        }
                    }
                }
            }
        } else {
            for (int i=0; i<R; i++) {
                for (int j=0; j<C; j++) {
                    if (arr[i][j] == 0) {
                        arr[i][j] = t+3;
                    }
                }
            }
        }
    }

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (arr[i][j]) cout << "O";
            else cout << ".";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
