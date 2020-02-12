#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int N;
int dp[50001]={0, 1};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  cin >> N;
  for(int i=2; i<=N; i++) {
    dp[i] = i;
    for(int j=2; j*j<=i; j++)
      dp[i] = min(dp[i-j*j]+1, dp[i]);
  }
  cout << dp[N];

  return 0;
}