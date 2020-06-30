#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int T; cin >> T;
  while(T--) {
    int N, arr[1005], res; cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];
    int dp[1005]={0,};
    res = dp[1] = arr[1];
    for(int i=2; i<=N; i++) {
      if(dp[i-1] > 0) dp[i] = dp[i-1] + arr[i];
      else dp[i] = arr[i];
      res = max(res, dp[i]);
    }
    cout << res << '\n';
  }
  
  return 0;
}