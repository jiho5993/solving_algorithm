#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

long long dp[35][35];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int H, N; cin >> H >> N;
    int diff = abs(H - N);
    dp[0][0] = 1;
    dp[1][0] = dp[1][1] = 1;
    for(int i=2; i<=diff; i++) {
        dp[i][0] = 1;
        for(int j=1; j<i; j++)
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        dp[i][i] = dp[i][i-1];
    }
    cout << dp[diff][diff];

    return 0;
}