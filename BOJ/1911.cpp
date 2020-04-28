#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N, L; cin >> N >> L;
  vector<pair<int, int> > v(N);
  for(int i=0; i<N; i++) cin >> v[i].first >> v[i].second;
  sort(all(v));
  int ret=0, idx=0;
  for(int i=0; i<N; i++) {
    if(idx >= v[i].second) continue;
    idx = max(idx, v[i].first);
    int cnt=(v[i].second-(idx+1))/L + 1;
    ret += cnt;
    idx += L*cnt;
  }
  cout << ret;
  
  return 0;
}