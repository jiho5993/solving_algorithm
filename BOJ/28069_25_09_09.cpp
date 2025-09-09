#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr
#define ll long long

#define tiib tuple<int, int, bool>

int N, K;
int dp[1000001];

void solve() {
    fill(dp, dp+1000001, 1e9);
    cin >> N >> K;

    dp[0] = 0;
    dp[1] = 1;

    for (int i=1; i<=N; i++) {
        if (i+1 <= N) dp[i+1] = min(dp[i+1], dp[i]+1);
        int n = i+(i/2);
        if (n <= N) dp[n] = min(dp[n], dp[i]+1);
    }

    if (dp[N] <= K) cout << "minigimbob";
    else cout << "water";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
