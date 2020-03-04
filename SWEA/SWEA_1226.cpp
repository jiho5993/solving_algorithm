#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int arr[20][20];
bool visit[20][20];

void Input() {
  memset(visit, 0, sizeof(visit));
  for(int i=0; i<16; i++) {
    string s; cin >> s;
    for(int j=0; j<16; j++)
      arr[i][j] = s[j]-'0';
  }
      
}

bool bfs() {
  queue<pair<int, int> > qp;
  qp.push({1, 1});
  visit[1][1] = 1;
  while(!qp.empty()) {
    int x = qp.front().first;
    int y = qp.front().second;
    qp.pop();
    if(arr[x][y] == 3) return true;
    for(int i=0; i<4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if(arr[xx][yy] != 1 && !visit[xx][yy]) {
        visit[xx][yy] = 1;
        qp.push({xx, yy});
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  int T;
  while(cin >> T) {
    Input();
    cout << "#" << T << ' ' << bfs() << '\n';
  }

  return 0;
}