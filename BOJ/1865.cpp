#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

#define INF 987654321
typedef pair<int, int> pii;

int N, M, W;
vector<vector<pii> > arr(501);
int dist[501];

bool foo() {
  dist[1] = 0;
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      for(auto k:arr[j]) {
        int tmp = k.first;
        int d = k.second;
        if(dist[j] != INF && dist[tmp] > d + dist[j]) {
          dist[tmp] = dist[j] + d;
          if(i == N) return true;
        }
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int T; cin >> T;
  while(T--) {
    cin >> N >> M >> W;
    for(int i=0; i<501; i++) arr[i].clear();
    fill(dist, dist+501, INF);
    for(int i=0; i<M+W; i++) {
      int s, e, t; cin >> s >> e >> t;
      if(i >= M) arr[s].pb({e, -t});
      else {
        arr[s].pb({e, t});
        arr[e].pb({s, t});
      }
    }
    if(foo()) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}