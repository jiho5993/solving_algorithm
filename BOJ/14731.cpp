#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
const ll MOD = 1e9+7;

ll fast_pow(ll a, ll b) {
  if(b == 0) return 1;
  ll n = fast_pow(a, b/2);
  ll tmp = (n*n)%MOD;
  if(b&1) return (a*tmp)%MOD;
  else return tmp%MOD;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  int N; cin >> N;
  ll ret=0;
  while(N--) {
    ll x, y; cin >> x >> y;
    if(y == 0) continue;
    ret = (ret + ((x*y)%MOD) * fast_pow(2, y-1))%MOD;
  }
  cout << ret;

  return 0;
}