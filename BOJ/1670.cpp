#include <bits/stdc++.h>
using namespace std;

const int MOD=987654321;
typedef long long ll;

int N;
ll dp[10001];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N;
    dp[0] = 1;
    for(int i=2; i<=N; i+=2) {
        for(int j=0; j<=i-2; j+=2) {
            dp[i] += dp[j] * dp[i-j-2];
            dp[i] %= MOD;
        }
    }
    cout << dp[N];

    return 0;
}