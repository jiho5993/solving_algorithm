#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

long long Q, M, a=1, b=1;
bool flag=false;
string s="11";

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  cin >> Q >> M;
  while(1) {
    if(!flag) {
      a = (a+b)%M;
      s += to_string(a);
    } else {
      b = (a+b)%M;
      s += to_string(b);
    }
    flag = !flag;
    if(a == 1 && b == 1) break;
  }
  s[s.size()-2]='\0';
  while(Q--) {
    long long idx; cin >> idx;
    cout << s[(idx-1)%(s.size()-2)] << '\n';
  }

  return 0;
}