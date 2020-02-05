#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int T; cin >> T;
  while(T--) {
    int K; cin >> K;
    multimap<int, bool> Q;
    while(K--) {
      char s; cin >> s;
      if(s == 'I') {
        int N; cin >> N;
        Q.insert(pair<int, bool>(N, 1));
      } else {
        int N; cin >> N;
        if(Q.empty()) continue;
        else {
          if(N == -1) Q.erase(Q.begin());
          else Q.erase(--Q.end());
        }
      }
    }
    if(Q.empty()) cout << "EMPTY\n";
    else cout << (--Q.end())->first << ' ' << Q.begin()->first << '\n';
  }

  return 0;
}