#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  for(int i=1; ; i++) {
    string s; getline(cin, s);
    if(s == "Was it a cat I saw?") break;
    for(int j=0; j<s.size(); j+=1+i) cout << s[j];
    cout << '\n';
  }

  return 0;
}