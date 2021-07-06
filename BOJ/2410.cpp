#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MOD = 1000000000;
int dp[1000001];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N; cin >> N;
    dp[0] = 1;
    for(int i=0; (1<<i)<=N; i++) {
        for(int j=0; j<=N; j++) {
            if(j >= (1<<i)) {
                dp[j] += dp[j-(1<<i)];
                dp[j] %= MOD;
            }
        }
    }
    cout << dp[N];

    return 0;
}