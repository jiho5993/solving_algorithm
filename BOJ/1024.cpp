#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;

ll N, L;
vector<ll> res;

bool bs(int c) {
  ll lo=0, hi=N, prev[2];
  while(lo < hi) {
    res.clear();
    ll mid = (lo+hi)/2;
    ll sum = 0;
    for(int i=0; i<c; i++) {
      sum += (mid+i);
      res.pb(mid+i);
    }
    prev[0] = lo;
    prev[1] = hi;
    if(sum == N) return true;
    else if(sum < N) lo = mid;
    else hi = mid;
    if(prev[0] == lo && prev[1] == hi) break;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  cin >> N >> L;
  bool flag = false;
  for(int i=L; i<=100; i++) {
    if(bs(i)) {
      for(auto ret : res) cout << ret << " ";
      flag = true;
      break;
    }
  }
  if(!flag) cout << "-1";
  
  return 0;
}