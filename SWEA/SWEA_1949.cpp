#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int arr[9][9], n, k, ans;
bool visit[9][9];

void dfs(int y, int x, int rs, int chk) {
    ans = max(ans, rs);
    fr(i, 0, 4) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
        if (visit[yy][xx]) continue;
        if (arr[y][x] <= arr[yy][xx]) {
            if (!chk) {
                fr(j, 1, k + 1) {
                    int tmp = arr[yy][xx];
                    int nxt = arr[yy][xx] - j;
                    if (arr[y][x] > nxt) {
                        visit[yy][xx] = 1;
                        arr[yy][xx] = nxt;
                        dfs(yy, xx, rs + 1, chk + 1);
                        arr[yy][xx] = tmp;
                        visit[yy][xx] = 0;
                    }
                }
            }
        } else {
            visit[yy][xx] = 1;
            dfs(yy, xx, rs + 1, chk);
            visit[yy][xx] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    fr(test, 1, t + 1) {
        fill(visit[0], visit[0] + 9 * 9, 0);
        int m = 0;
        cin >> n >> k;
        fr(i, 0, n) {
            fr(j, 0, n) {
                cin >> arr[i][j];
                m = max(m, arr[i][j]);
            }
        }
        ans = 0;
        fr(i, 0, n) {
            fr(j, 0, n) {
                if (arr[i][j] == m && !visit[i][j]) {
                    visit[i][j] = 1;
                    dfs(i, j, 1, 0);
                    visit[i][j] = 0;
                }
            }
        }
        cout << "#" << test << ' ' << ans << '\n';
    }

    return 0;
}