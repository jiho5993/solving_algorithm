#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
ll x, y, w, s;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  cin >> x >> y >> w >> s;
  ll mod = (x+y)%2;
  if(x < y) swap(x, y);
  cout << min((x+y)*w, min((x-mod)*s + mod*w, y*s + (x-y)*w));
  
  return 0;
}