#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int T; cin >> T;
  while(T--) {
    int N; cin >> N;
    map<string, int> m;
    for(int i=0; i<N; i++) {
      string s1, s2;
      cin >> s1 >> s2;
      if(m[s2]) m[s2]++;
      else m[s2] = 1;
    }
    int rs=1;
    for(auto i:m) rs *= i.second+1;
    cout << rs-1 << '\n';
  }

  return 0;
}