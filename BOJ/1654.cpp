#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
ll arr[10001];

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  ll K, N, mx=0; cin >> K >> N;
  for(int i=0; i<K; i++) {
    cin >> arr[i];
    mx = max(mx, arr[i]);
  }
  ll lo=1, hi=mx;
  ll rs = hi;
  while(lo <= hi) {
    ll mid = (lo+hi)/2;
    ll cnt = 0;
    for(int i=0; i<K; i++) cnt += (arr[i]/mid);
    if(cnt >= N) {
      lo = mid+1;
      rs = mid;
    } else hi = mid-1;
  }
  cout << rs;
  
  return 0;
}