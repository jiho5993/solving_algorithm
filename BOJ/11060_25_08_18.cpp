#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int N;
int arr[1001];
int dp[1001];

void solve() {
    fill(dp, dp+1001, 1e9);

    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];

    dp[0] = 0;
    for (int i=0; i<N; i++) {
        for (int j=1; j<=arr[i]; j++) {
            if (i+j > N) break;
            dp[i+j] = min(dp[i]+1, dp[i+j]);
        }
    }

    if (dp[N-1] == 1e9) cout << -1;
    else cout << dp[N-1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
