#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  string s; cin >> s;
  s = "A" + s;
  int rs=0;
  for(int i=1; i<s.size(); i++) rs += min(abs(s[i]-s[i-1]), 26-abs(s[i]-s[i-1]));
  cout << rs;

  return 0;
}