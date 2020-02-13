#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int n, tmp=1, rs=1, v=6; cin >> n;
  while(1) {
    if(n <= tmp) break;
    rs++;
    tmp += v;
    v += 6;
  }
  cout << rs;

  return 0;
}