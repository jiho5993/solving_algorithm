#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001] = {1,};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, K; cin >> N >> K;
    dp[1][0] = dp[1][1] = 1;
    for (int i=2; i<=N; i++) {
        dp[i][0] = dp[i][i] = 1;
        for (int j=1; j<=i-1; j++) dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % 10007;
    }

    cout << dp[N][K];

    return 0;
}
