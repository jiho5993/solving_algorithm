#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

const ll MOD = 1e9 + 9;
ll dp[100005][4];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int T; cin >> T;
    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
    for(int i=4; i<=100000; i++) {
        dp[i][1] = (dp[i-1][2]+dp[i-1][3])%MOD;
        dp[i][2] = (dp[i-2][1]+dp[i-2][3])%MOD;
        dp[i][3] = (dp[i-3][1]+dp[i-3][2])%MOD;
    }
    while(T--) {
        int N; cin >> N;
        cout << (dp[N][1]+dp[N][2]+dp[N][3])%MOD << '\n';
    }

    return 0;
}