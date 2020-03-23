#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  int n, a, b, c=0; cin >> n;
  if(n == 2) cin >> a >> b;
  if(n == 3) cin >> a >> b >> c;
  for(int i=1; i<=min(a, b); i++)
    if(a%i == 0 && b%i == 0 && c%i == 0)
      cout << i << '\n';

  return 0;
}