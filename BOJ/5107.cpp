#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N, tc=1;
  while(1) {
    cin >> N;
    if(N == 0) break;
    map<string, pair<string, bool> > m;
    string arr[21];
    for(int i=0; i<N; i++) {
      string a, b; cin >> a >> b;
      m[a] = {b, false};
      arr[i] = a;
    }
    int ret=0;
    for(int i=0; i<N; i++) {
      string tmp = arr[i];
      if(m[tmp].second) continue;
      m[tmp].second = true;
      string c = m[tmp].first;
      while(tmp != c) {
        m[c].second = true;
        c = m[c].first;
      }
      ret++;
    }
    cout << tc << ' ' << ret << '\n';
    tc++;
  }
  
  return 0;
}