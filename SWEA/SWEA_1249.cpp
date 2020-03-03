#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int N;
int arr[101][101];
int dist[101][101];
bool visit[101][101];

void Init() {
  memset(arr, 0, sizeof(arr));
  memset(visit, 0, sizeof(visit));
  memset(dist, 0, sizeof(dist));
  cin >> N;
  for(int i=0; i<N; i++) {
    string s; cin >> s;
    for(int j=0; j<N; j++)
      arr[i][j] = s[j]-'0';
  }
}

void bfs() {
  queue<pair<int, int> > qp;
  qp.push({0, 0});
  visit[0][0] = 1;
  while(!qp.empty()) {
    int x = qp.front().first;
    int y = qp.front().second;
    qp.pop();
    if(x == N-1 && y == N-1) continue;
    for(int i=0; i<4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if((0 <= xx && xx < N) && (0 <= yy && yy < N)) {
        if(!visit[xx][yy] || dist[xx][yy] > dist[x][y] + arr[xx][yy]) {
          dist[xx][yy] = dist[x][y] + arr[xx][yy];
          visit[xx][yy] = 1;
          qp.push({xx, yy});
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  int T; cin >> T;
  for(int tc=1; tc<=T; tc++) {
    Init();
    bfs();
    cout << "#" << tc << ' ' << dist[N-1][N-1] << '\n';
  }

  return 0;
}