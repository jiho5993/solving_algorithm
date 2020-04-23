#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
int N;
int arr[101];
ll dp[21][101];

ll foo(int num, int idx) {
  if(num < 0 || num > 20) return 0;
  if(idx == N-2) return num == arr[N-1];
  ll &rs = dp[num][idx];
  if(rs != -1) return rs;
  rs = 0;
  ll a = foo(num+arr[idx+1], idx+1);
  ll b = foo(num-arr[idx+1], idx+1);
  rs += a+b;
  return rs;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  cin >> N;
  for(int i=0; i<N; i++) cin >> arr[i];
  memset(dp, -1, sizeof(dp));
  cout << foo(arr[0], 0);
  
  return 0;
}