#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
const int MOD = 1e9+7;
ll dp[51][51][51][51];

ll foo(int s, int a, int b, int c) {
  if(!s) {
    if(!a && !b && !c) return 1;
    else return 0;
  }
  if(a < 0 || b < 0 || c < 0) return 0;
  if(dp[s][a][b][c] != -1) return dp[s][a][b][c];

  ll ret = 0;
  ret += foo(s-1, a-1, b, c);
  ret += foo(s-1, a, b-1, c);
  ret += foo(s-1, a, b, c-1);
  ret += foo(s-1, a-1, b-1, c);
  ret += foo(s-1, a-1, b, c-1);
  ret += foo(s-1, a, b-1, c-1);
  ret += foo(s-1, a-1, b-1, c-1);
  ret %= MOD;
  dp[s][a][b][c] = ret;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int s, a, b, c;
  cin >> s >> a >> b >> c;
  memset(dp, -1, sizeof(dp));
  cout << foo(s, a, b, c);
  
  return 0;
}