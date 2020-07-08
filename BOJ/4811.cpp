#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
ll dp[31][31];

ll foo(int w, int h) {
  if(w == 0) return 1;
  if(dp[w][h] != -1) return dp[w][h];
  dp[w][h] = foo(w-1, h+1);
  if(h > 0) dp[w][h] += foo(w, h-1);
  return dp[w][h];
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N;
  while(cin >> N) {
    if(N == 0) break;
    memset(dp, -1, sizeof(dp));
    cout << foo(N, 0) << '\n';
  }
  
  return 0;
}