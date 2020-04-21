#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int N, M, K;
string res;
string arr[101];
vector<pair<int, int> > v;
int dp[101][101][81];

int dfs(int y, int x, int idx) {
  if(dp[y][x][idx] != -1) return dp[y][x][idx];
  if(idx == res.size()) return 1;

  dp[y][x][idx] = 0;
  for(int i=0; i<4; i++) {
    for(int j=1; j<=K; j++) {
      int yy = y + j*dy[i];
      int xx = x + j*dx[i];
      if(yy < 0 || yy >= N || xx < 0 || xx >= M) break;
      if(arr[yy][xx] == res[idx])
        dp[y][x][idx] += dfs(yy, xx, idx+1);
    }
  }
  return dp[y][x][idx];
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  cin >> N >> M >> K;
  for(int i=0; i<N; i++) cin >> arr[i];
  cin >> res;
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      if(res[0] == arr[i][j])
        v.pb({i, j});
  
  int ret = 0;
  memset(dp, -1, sizeof(dp));
  for(auto i:v) ret += dfs(i.first, i.second, 1);
  cout << ret << '\n';
  
  return 0;
}