#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int N, M;
pair<int, int> p;
int arr[1001][1001];
bool visit[1001][1001];

void bfs() {
  queue<pair<int, int> > qp;
  qp.push(p);
  visit[p.first][p.second] = 1;
  while(!qp.empty()) {
    int x = qp.front().second;
    int y = qp.front().first;
    qp.pop();
    for(int i=0; i<4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if((0 <= xx && xx < M) && (0 <= yy && yy < N)) {
        if(!visit[yy][xx] && arr[yy][xx]) {
          qp.push({yy, xx});
          arr[yy][xx] = arr[y][x] + 1;
          visit[yy][xx] = 1;
        }
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
      if(arr[i][j] == 2) {
        p = {i, j};
        arr[i][j] = 0;
      }
    }
  }
  bfs();
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      if(!visit[i][j] && arr[i][j] == 1) cout << "-1 ";
      else cout << arr[i][j] << ' ';
    }
    cout << '\n';
  }
  
  return 0;
}