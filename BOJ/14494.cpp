#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9+7;
int dp[1001][1001];

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N, M; cin >> N >> M;
  dp[1][1] = 1;
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=M; j++) {
      if(i == 1 && j == 1) continue;
      if(i == 1) dp[i][j] = dp[i][j-1];
      else if(j == 1) dp[i][j] = dp[i-1][j];
      else dp[i][j] = ((dp[i-1][j]+dp[i][j-1])%MOD+dp[i-1][j-1])%MOD;
    }
  }
  cout << dp[N][M];

  return 0;
}