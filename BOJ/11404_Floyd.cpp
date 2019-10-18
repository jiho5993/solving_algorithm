#include <bits/stdc++.h>
using namespace std;

#define INF 100001

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N, M; cin >> N >> M;
    vector<vector<int> > dp(N+1, vector<int>(N+1, INF));
    for(int i=1; i<=N; i++) dp[i][i] = 0;
    while(M--) {
        int a, b, c; cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
    }

    for(int k=1; k<=N; k++)
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
    
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++)
            dp[i][j] == INF ? cout << "0 " : cout << dp[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}