#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

struct info {
  int st, in, ptr;
};

int N;
info arr[101];
int dp[1001][1001];
bool visit[101];

int foo(int st, int in) {
  int &rs = dp[st][in];
  if(rs != -1) return rs;
  int ptr=0, cnt=0;
  vector<int> v;
  for(int i=0; i<N; i++) {
    if(arr[i].st <= st || arr[i].in <= in) {
      if(!visit[i]) {
        visit[i] = 1;
        v.pb(i);
        ptr += arr[i].ptr;
      }
      cnt++;
    }
  }
  rs = cnt;
  for(int i=st; i<=min(1000, st+ptr); i++)
    rs = max(rs, foo(i, min(1000, in+(ptr-(i-st)))));
  for(auto i:v) visit[i] = 0;
  return rs;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  cin >> N;
  for(int i=0; i<N; i++) {
    int a, b, c; cin >> a >> b >> c;
    arr[i] = {a, b, c};
  }
  memset(dp, -1, sizeof(dp));
  cout << foo(1, 1);
  
  return 0;
}