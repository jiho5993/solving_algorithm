#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
const int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
int N, M;
bool arr[251][251];
bool visit[251][251];
vector<pair<int, int> > vp;

void bfs(int y, int x) {
  queue<pair<int, int> > qp;
  visit[y][x] = 1;
  qp.push({y, x});
  while(!qp.empty()) {
    int x = qp.front().second;
    int y = qp.front().first;
    qp.pop();
    for(int i=0; i<8; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if((0 <= xx && xx < M) && (0 <= yy && yy < N) && !visit[yy][xx] && arr[yy][xx]) {
        qp.push({yy, xx});
        visit[yy][xx] = 1;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  cin >> N >> M;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      cin >> arr[i][j];
      if(arr[i][j]) vp.pb({i, j});
    }
  }
  int ret=0;
  for(auto i:vp) {
    int y = i.first;
    int x = i.second;
    if(!visit[y][x]) {
      ret++;
      bfs(y, x);
    }
  }
  cout << ret;
  
  return 0;
}