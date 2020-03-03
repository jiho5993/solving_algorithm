#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

const int dx[]={1, -1, 0, 0};
const int dy[]={0, 0, 1, -1};

int arr[4][4];
map<string, int> m;

void Input() {
  m.clear();
  for(int i=0; i<4; i++)
    for(int j=0; j<4; j++)
      cin >> arr[i][j];
}

void dfs(string s, int x, int y) {
  if(s.size() == 7) {
    m[s]++;
    return;
  }
  s += arr[x][y];
  for(int i=0; i<4; i++) {
    int xx = x+dx[i];
    int yy = y+dy[i];
    if((0 <= xx && xx < 4) && (0 <= yy && yy < 4))
      dfs(s, xx, yy);
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  int T; cin >> T;
  for(int i=1; i<=T; i++) {
    Input();
    for(int j=0; j<4; j++)
      for(int k=0; k<4; k++)
        dfs("", j, k);
    cout << "#" << i << ' ' << m.size() << '\n';
  }

  return 0;
}