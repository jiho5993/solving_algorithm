#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int N, M;
int ret=0;
pair<int, int> p[2];
char arr[301][301];
char tmp[301][301];
bool visit[301][301];

bool bfs() {
  queue<pair<int, int> > qp;
  qp.push(p[0]);
  while(!qp.empty()) {
    int x = qp.front().second;
    int y = qp.front().first;
    qp.pop();
    for(int i=0; i<4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if((1 <= xx && xx <= M) && (1 <= yy && yy <= N) && !visit[yy][xx]) {
        visit[yy][xx] = 1;
        if(arr[yy][xx] == '#') return true;
        if(arr[yy][xx] == '1') {
          tmp[yy][xx] = '0';
          continue;
        }
        qp.push({yy, xx});
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  cin >> N >> M;
  for(int i=0; i<2; i++) {
    int a, b; cin >> a >> b;
    p[i] = {a, b};
  }
  for(int i=1; i<=N; i++) {
    string s; cin >> s;
    for(int j=1; j<=M; j++)
      arr[i][j] = s[j-1];
  }

  while(1) {
    ret++;
    memset(visit, 0, sizeof(visit));
    memcpy(tmp, arr, sizeof(tmp));
    if(bfs()) break;
    memcpy(arr, tmp, sizeof(tmp));
  }
  cout << ret;
  
  return 0;
}