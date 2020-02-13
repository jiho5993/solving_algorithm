#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef pair<int, int> pii;
vector<pii> arr[100001];

pii bfs(int st) {
  queue<pii> qp;
  bool visit[100001]={0,};
  qp.push({st, 0});
  visit[st] = 1;
  pii ret={0, 0};
  while(!qp.empty()) {
    int tmp = qp.front().first;
    int w = qp.front().second;
    qp.pop();
    if(ret.second <= w) ret = {tmp, w};
    for(auto i:arr[tmp]) {
      int nxt = i.first;
      int ww = i.second;
      if(!visit[nxt]) {
        visit[nxt] = 1;
        qp.push({nxt, w+ww});
      }
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int V; cin >> V;
  for(int i=0; i<V; i++) {
    int v; cin >> v;
    while(1) {
      int a, b; cin >> a;
      if(a == -1) break;
      cin >> b;
      arr[v].pb({a, b});
    }
  }
  int st=bfs(1).first;
  cout << bfs(st).second;

  return 0;
}