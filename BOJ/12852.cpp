#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int dp[1000001] = {0, 0,};

void print(int n) {
  if(n == 0) return;
  cout << n << ' ';
  if(n%3 == 0 && dp[n] == dp[n/3]+1) print(n/3);
  else if(n%2 == 0 && dp[n] == dp[n/2]+1) print(n/2);
  else if(dp[n] = dp[n-1]+1) print(n-1);
  return;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int n; cin >> n;
  for(int i=2; i<=n; i++) {
    dp[i] = dp[i-1]+1;
    if(i%2 == 0) dp[i] = min(dp[i], dp[i/2]+1);
    if(i%3 == 0) dp[i] = min(dp[i], dp[i/3]+1);
  }
  cout << dp[n] << '\n';
  print(n);

  return 0;
}