#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

string S, bomb;
char ans[1000001];

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  cin >> S >> bomb;
  int sz = bomb.size(), idx=0;
  for(int i=0; i<S.size(); i++) {
    ans[idx++] = S[i];
    if(bomb[sz-1] == ans[idx-1]) {
      if(idx-sz < 0) continue;
      bool detected = true;
      for(int j=0; j<sz; j++) {
        if(ans[idx-1-j] != bomb[sz-1-j]) {
          detected = false;
          break;
        }
      }
      if(detected) idx -= sz;
    }
  }
  ans[idx] = '\0';
  if(!idx) cout << "FRULA";
  else cout << ans;

  return 0;
}