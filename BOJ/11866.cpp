#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N, K; cin >> N >> K;
  vector<int> v, rs;
  for(int i=1; i<=N; i++) v.pb(i);
  int idx=0, cnt=1;
  while(v.size()) {
    if(cnt == K) {
      rs.pb(v[idx]);
      v.erase(v.begin()+idx);
      idx--;
      cnt = 0;
    }
    else {
      cnt++;
      idx++;
    }
    if(idx == v.size()) idx=0;
  }
  cout << "<";
  for(int i=0; i<N; i++) {
    if(i == N-1) cout << rs[i];
    else cout << rs[i] << ", ";
  }
  cout << ">";

  return 0;
}