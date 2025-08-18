#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int dp[101][10001];
pair<int, int> arr[101];

void solve() {
    int N, T; cin >> N >> T;

    for (int i=1; i<=N; i++) {
        int a, b; cin >> a >> b;
        arr[i] = {a, b};
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=T; j++) {
            if (j >= arr[i].first) dp[i][j] = max(dp[i-1][j], dp[i-1][j-arr[i].first]+arr[i].second);
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[N][T];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
