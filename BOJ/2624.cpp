#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int T, k;
pair<int, int> arr[101];
int dp[10001][101];

int foo(int price, int idx) {
  if(price == 0) return 1;
  if(idx >= k) return 0;
  int &rs = dp[price][idx];
  if(rs != -1) return rs;
  rs = 0;
  for(int i=0; i<=arr[idx].second; i++) {
    int tmp = price-arr[idx].first*i;
    if(tmp >= 0)
      rs += foo(tmp, idx+1);
  }
  return rs;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  cin >> T >> k;
  for(int i=0; i<k; i++) {
    int a, b; cin >> a >> b;
    arr[i] = {a, b};
  }
  memset(dp, -1, sizeof(dp));
  cout << foo(T, 0);
  
  return 0;
}