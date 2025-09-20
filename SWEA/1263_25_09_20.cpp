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

int N;
bool arr[1001][1001];
int dist[1001][1001];

void solve() {
    int T; cin >> T;
    for (int tc=1; tc<=T; tc++) {
        memset(arr, 0, sizeof(arr));
        for (int i=0; i<1001; i++) {
            fill(dist[i], dist[i]+1001, 1e9);
            dist[i][i] = 0;
        }

        cin >> N;
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                cin >> arr[i][j];
                if (arr[i][j]) dist[i][j] = 1;
            }
        }

        for (int k=1; k<=N; k++) {
            for (int i=1; i<=N; i++) {
                for (int j=1; j<=N; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int res = 1e9;
        for (int i=1; i<=N; i++) {
            int s = 0;
            for (int j=1; j<=N; j++) s += dist[i][j];
            res = min(res, s);
        }

        cout << "#" << tc << ' ' << res << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
