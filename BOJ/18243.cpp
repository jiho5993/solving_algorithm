#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

vector<vector<int> > arr(101);
int visit[101];

void bfs(int n) {
  queue<int> q;
  visit[n] = 0;
  q.push(n);
  while(!q.empty()) {
    int tmp = q.front();
    q.pop();
    for(auto i : arr[tmp]) {
      if(visit[i] == -1) {
        q.push(i);
        visit[i] = visit[tmp]+1;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N, K; cin >> N >> K;
  for(int i=0; i<K; i++) {
    int a, b; cin >> a >> b;
    arr[a].pb(b);
    arr[b].pb(a);
  }
  for(int i=1; i<=N; i++) {
    memset(visit, -1, sizeof(visit));
    bfs(i);
    for(int j=1; j<=N; j++) {
      if(visit[j] == -1 || visit[j] > 6) {
        cout << "Big World!";
        return 0;
      }
    }
  }
  cout << "Small World!";

  return 0;
}