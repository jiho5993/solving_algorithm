#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N; cin >> N;
  string s="";
  for(int i=0; i<N; i++) {
    int a; cin >> a;
    if(27 <= a && a <= 52) {
      a -= 27;
      s += ('a'+a);
    }
    else if(1 <= a && a <= 26) s += ('A'+a-1);
    else s += ' ';
  }
  cin.ignore();
  string code; getline(cin, code);
  sort(all(code));
  sort(all(s));
  code == s ? cout << 'y' : cout << 'n';
  
  return 0;
}