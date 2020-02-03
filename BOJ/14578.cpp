#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

#define MOD 1000000007
typedef long long ll;

ll fac = 2;
ll arr[100001] = {0, 0, 1, };

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N; cin >> N;
  for(int i=3; i<=N; i++) {
    arr[i] = (i-1)*(arr[i-1]+arr[i-2]);
    arr[i] %= MOD;
    fac *= i;
    fac %= MOD;
  }
  cout << (fac*arr[N])%MOD;

  return 0;
}