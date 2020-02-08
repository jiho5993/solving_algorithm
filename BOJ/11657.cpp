#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

#define INF 987654321
typedef pair<int, int> pii;

int N, M;
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

  cin >> N >> M;
  fill(dist, dist+501, INF);
  for(int i=0; i<M; i++) {
    int a, b, c; cin >> a >> b >> c;
    arr[a].pb({b, c});
  }
  if(foo()) cout << "-1";
  else {
    for(int i=2; i<=N; i++) {
      if(dist[i] == INF) cout << "-1\n";
      else cout << dist[i] << '\n';
    }
  }

  return 0;
}