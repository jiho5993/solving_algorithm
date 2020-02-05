#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int T; cin >> T;
  while(T--) {
    int a, b, c; cin >> a >> b >> c;
    int x = c%a, y = c/a+1;
    if(!x) x = a;
    if(!(c%a)) y--;
    cout << x*100+y << '\n';
  }

  return 0;
}