#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
const ll MOD = 1e9+7;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  int N; cin >> N;
  ll ret=0;
  while(N--) {
    ll x, y; cin >> x >> y;
    ll a=1, b=2, c=y-1;
    while(c) {
      if(c&1) a = (a*b)%MOD;
      b = (b*b)%MOD;
      c /= 2;
    }
    if(y) ret = (ret+((x*y)%MOD)*a)%MOD;
  }
  cout << ret;

  return 0;
}