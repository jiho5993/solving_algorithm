#include <bits/stdc++.h>
using namespace std;

int dp[100001] = {0, 1, 1, 2, 2, 1, 2, 1, };

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n; cin >> n;
    for(int i=8; i<=n; i++) {
        if(i%7 == 0) dp[i] = dp[i-7] + 1;
        else dp[i] = min(min(dp[i-5], dp[i-2]), dp[i-1]) + 1;
    }
    cout << dp[n];

    return 0;
}