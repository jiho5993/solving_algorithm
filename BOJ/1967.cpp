#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef pair<int, int> pii;
vector<pii> arr[10001];

pii bfs(int st) {
  queue<pii> qp;
  bool visit[10001]={0,};
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

  int N; cin >> N;
  for(int i=0; i<N-1; i++) {
    int a, b, c; cin >> a >> b >> c;
    arr[a].pb({b, c});
    arr[b].pb({a, c});
  }
  int st=bfs(1).first;
  cout << bfs(st).second;

  return 0;
}