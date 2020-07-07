#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N, ret=-1;
  cin >> N;
  while(N--) {
    int a; cin >> a;
    ret = max(ret, a);
  }
  cout << ret;

  return 0;
}