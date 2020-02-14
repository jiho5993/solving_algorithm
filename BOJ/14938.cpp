#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int N, M, R;
int item[101];
vector<vector<int> > dp(101, vector<int>(101, 987654321));

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  cin >> N >> M >> R;
  for(int i=1; i<=N; i++) {
    cin >> item[i];
    dp[i][i] = 0;
  }
  for(int i=0; i<R; i++) {
    int a, b, c; cin >> a >> b >> c;
    dp[a][b] = dp[b][a] = c;
  }
  for(int k=1; k<=N; k++)
    for(int i=1; i<=N; i++)
      for(int j=1; j<=N; j++)
        dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);

  int rs=0;
  for(int i=1; i<=N; i++) {
    int tmp=0;
    for(int j=1; j<=N; j++) {
      if(dp[i][j] <= M)
        tmp += item[j];
    }
    rs = max(rs, tmp);
  }
  cout << rs;

  return 0;
}