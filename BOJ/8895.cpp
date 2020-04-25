#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
int N, L, R;
ll dp[101][101][101];

ll foo(int num, int l, int r) {
  if((l == 1 && r == num) || (l == num && r == 1)) return 1;
  if(!num || !l || !r) return 0;
  ll &ret = dp[num][l][r];
  if(ret != -1) return ret;
  ret = (foo(num-1, l, r)*(num-2) + foo(num-1, l-1, r) + foo(num-1, l, r-1));
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int T; cin >> T;
  while(T--) {
    cin >> N >> L >> R;
    memset(dp, -1, sizeof(dp));
    cout << foo(N, L, R) << '\n';
  }
  
  return 0;
}