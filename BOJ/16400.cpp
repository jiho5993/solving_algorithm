#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()]

const int MOD = 123456789;
bool p[40001];
int dp[40001];
vector<int> prime;

void eratos(int n) {
  for(int i=2; i*i<=n; i++) {
    if(p[i]) continue;
    for(int j=i*2; j<=n; j+=i) p[j] = 1;
  }
  for(int i=2; i<=n; i++)
    if(!p[i])
      prime.pb(i);
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N; cin >> N;
  eratos(N);
  dp[0] = 1;
  for(auto i:prime)
    for(int j=i; j<=N; j++)
      dp[j] = (dp[j] + dp[j-i])%MOD;
  cout << dp[N];
  
  return 0;
}