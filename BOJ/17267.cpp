#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

struct info {
  int y, x, l, r;
};

int N, M, L, R;
int arr[1001][1001];
bool visit[1001][1001];
queue<info> q;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void Input() {
  cin >> N >> M >> L >> R;
  for(int i=0; i<N; i++) {
    string s; cin >> s;
    for(int j=0; j<M; j++) {
      if(s[j] == '2') {
        q.push({i, j, L, R});
        visit[i][j] = 1;
      }
      arr[i][j] = s[j]-'0';
    }
  }
}

bool chk(int yy, int xx) {
  return (0 <= xx && xx < M) && (0 <= yy && yy < N) && !visit[yy][xx] && arr[yy][xx] != 1;
}

void bfs() {
  while(!q.empty()) {
    info tmp = q.front();
    int x = tmp.x, y = tmp.y;
    int l = tmp.l, r = tmp.r;
    q.pop();
    for(int i=2; i<4; i++) { // up, down
      int xx = x, yy = y;
      while(1) {
        yy += dy[i];
        if(!(0 <= yy && yy < N)) break;
        if(arr[yy][xx] == 1) break;
        if(chk(yy, xx)) {
          visit[yy][xx] = 1;
          q.push({yy, xx, l, r});
        }
      }
    }
    for(int i=0; i<2; i++) { // left, right
      int xx = x + dx[i], yy = y;
      if((i == 0 && r == 0) || (i == 1 && l == 0)) continue;
      if(chk(yy, xx)) {
        visit[yy][xx] = 1;
        if(i == 0) q.push({yy, xx, l, r-1});
        else q.push({yy, xx, l-1, r});
      }
    }
  }
  int ret=0;
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      ret += visit[i][j];
  cout << ret;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  Input();
  bfs();

  return 0;
}