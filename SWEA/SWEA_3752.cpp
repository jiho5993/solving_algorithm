#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int n, arr[101];
bool dp[10001];

void Input() {
  memset(dp, 0, sizeof(dp));
  memset(arr, 0, sizeof(arr));
  dp[0] = 1;
  cin >> n;
  for(int i=1; i<=n; i++) cin >> arr[i];
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  int T; cin >> T;
  for(int tc=1; tc<=T; tc++) {
    Input();
    for(int i=1; i<=n; i++) {
      for(int j=10000; j>=0; j--) {
        if(dp[j])
          dp[j+arr[i]] = 1;
      }
    }
    int ret=0;
    for(int i=0; i<=10000; i++) ret += dp[i];
    cout << "#" << tc << ' ' << ret << '\n';
  }

  return 0;
}