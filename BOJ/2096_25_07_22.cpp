#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int arr[100001][3];
int dp[2][3];

int min_3(int a, int b, int c) {
    return min(a, min(b, c));
}

int max_3(int a, int b, int c) {
    return max(a, max(b, c));
}

void solve() {
    int N; cin >> N;
    for (int i=0; i<N; i++) {
        int a, b, c; cin >> a >> b >> c;
        arr[i][0] = a;
        arr[i][1] = b;
        arr[i][2] = c;
    }

    dp[0][0] = dp[1][0] = arr[0][0];
    dp[0][1] = dp[1][1] = arr[0][1];
    dp[0][2] = dp[1][2] = arr[0][2];

    for (int i=1; i<N; i++) {
        int cp[3];
        cp[0] = min(dp[0][0], dp[0][1]) + arr[i][0];
        cp[1] = min_3(dp[0][0], dp[0][1], dp[0][2]) + arr[i][1];
        cp[2] = min(dp[0][1], dp[0][2]) + arr[i][2];

        memcpy(dp[0], cp, sizeof(cp));

        cp[0] = max(dp[1][0], dp[1][1]) + arr[i][0];
        cp[1] = max_3(dp[1][0], dp[1][1], dp[1][2]) + arr[i][1];
        cp[2] = max(dp[1][1], dp[1][2]) + arr[i][2];
        
        memcpy(dp[1], cp, sizeof(cp));
    }

    cout << max_3(dp[1][0], dp[1][1], dp[1][2]) << ' ';
    cout << min_3(dp[0][0], dp[0][1], dp[0][2]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
