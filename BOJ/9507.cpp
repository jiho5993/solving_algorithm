#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

long long dp[68]={1, 1, 2, 4, };

void foo() {
  for(int i=4; i<=67; i++)
    dp[i] = dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4];
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int T; cin >> T;
  foo();
  while(T--) {
    int a; cin >> a;
    cout << dp[a] << '\n';
  }
  
  return 0;
}