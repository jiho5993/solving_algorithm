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

#define MAX 10001

struct Shark {
    int x, y, s, d, z;
};

int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};
int R, C, M;
Shark sk[MAX];
int arr[101][101];
bool del[MAX];

int get_shark(int c) {
    for (int r=1; r<=R; r++) {
        int idx = arr[r][c];
        if (idx == 0) continue;
        del[idx] = true;
        arr[r][c] = 0;
        return sk[idx].z;
    }
    return 0;
}

void move_s() {
    int cp[101][101];
    memset(cp, 0, sizeof(cp));

    for (int i=1; i<=M; i++) {
        if (del[i]) continue;

        int x = sk[i].x, y = sk[i].y;
        int s = sk[i].s, d = sk[i].d;

        if (d == 1 || d == 2) { // u, d
            int mod = (R-1)*2;
            s %= mod;
            for (int g=0; g<s; g++) {
                x += dx[d];
                y += dy[d];
                if (x < 1) {
                    d = 2;
                    x = 2;
                } else if (x > R) {
                    d = 1;
                    x = R-1;
                }
            }
        } else { // l, r
            int mod = (C-1)*2;
            s %= mod;
            for (int g=0; g<s; g++) {
                x += dx[d];
                y += dy[d];
                if (y < 1) {
                    d = 3;
                    y = 2;
                } else if (y > C) {
                    d = 4;
                    y = C-1;
                }
            }
        }

        sk[i].x = x;
        sk[i].y = y;
        sk[i].d = d;
    
        if (cp[x][y] == 0) {
            cp[x][y] = i;
        } else {
            if (sk[i].z > sk[cp[x][y]].z) {
                del[cp[x][y]] = true;
                cp[x][y] = i;
            } else {
                del[i] = true;
            }
        }
    }

    memcpy(arr, cp, sizeof(arr));
}

void solve() {
    cin >> R >> C >> M;
    for (int i=1; i<=M; i++) {
        int r, c, s, d, z; cin >> r >> c >> s >> d >> z;
        sk[i] = {r, c, s, d, z};
        arr[r][c] = i;
    }

    int res = 0;
    for (int c=1; c<=C; c++) {
        res += get_shark(c);
        move_s();
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
