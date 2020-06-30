#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef pair<int, int> pii;
int N, M;
vector<pii> arr[1005];
int dist[1005];
int trace[1005];

int dij(int st, int en) {
  fill(dist, dist+N+1, 2e9);
  dist[1] = 0;
  priority_queue<pii> pq;
  pq.push({0, 1});
  while(!pq.empty()) {
    int tmp = pq.top().second;
    int cost = -pq.top().first;
    pq.pop();
    if(dist[tmp] < cost) continue;
    for(auto i:arr[tmp]) {
      int nxt = i.first;
      int nc = i.second + cost;
      if(tmp == st && nxt == en) continue;
      if(tmp == en && nxt == st) continue;
      if(dist[nxt] > nc) {
        dist[nxt] = nc;
        pq.push({-nc, nxt});
        if(st == 0) trace[nxt] = tmp;
      }
    }
  }

  return dist[N];
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  cin >> N >> M;
  for(int i=0; i<M; i++) {
    int a, b, c; cin >> a >> b >> c;
    arr[a].pb({b, c});
    arr[b].pb({a, c});
  }
  int f=dij(0, 0), ret=0;
  for(int i=N; i!=1; i=trace[i]) {
    int get=dij(i, trace[i]);
    if(get == 2e9) {
      cout << "-1";
      return 0;
    } else ret = max(ret, dist[N]);
  }
  cout << ret-f;
}