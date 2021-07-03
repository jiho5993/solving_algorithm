#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int N, K;
int dp[101][101][2];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int T; cin >> T;
    dp[1][0][0] = dp[1][0][1] = 1;
    for(int n=2; n<=100; n++) {
        for(int k=0; k<n; k++) {
            dp[n][k][0] = dp[n-1][k][0] + dp[n-1][k][1];
            dp[n][k][1] = dp[n-1][k][0] + dp[n-1][k-1][1];
        }
    }
    while(T--) {
        cin >> N >> K;
        cout << dp[N][K][0] + dp[N][K][1] << '\n';
    }

    return 0;
}