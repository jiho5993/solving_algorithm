#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int arr[101];
int dp[10001];

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N, K; cin >> N >> K;
  for(int i=1; i<=K; i++) dp[i] = 10001;
  for(int i=1; i<=N; i++) {
    int t; cin >> t;
    for(int j=t; j<=K; j++)
      dp[j] = min(dp[j], dp[j-t]+1);
  }
  if(dp[K] == 10001) cout << "-1";
  else cout << dp[K];
  
  return 0;
}