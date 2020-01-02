#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

char arr[101][101];

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N, M; cin >> N >> M;
  bool st=false, en=false;
  pair<int, int> p[2];
  for(int i=0; i<N; i++) {
    string s; cin >> s;
    for(int j=0; j<M; j++) {
      arr[i][j] = s[j];
      if(!st && s[j] == '#') {
        st = true;
        p[0] = {i, j};
      }
    }
  }
  for(int i=0; i<N; i++) {
    for(int j=M-1; j>=0; j--) {
      if(arr[i][j] == '#' && !en) {
        en = true;
        p[1] = {i, j};
      }
    }
    if(en) break;
  }
  int a=p[0].first, b=p[0].second;
  int c=p[1].first, d=p[1].second;
  int diff = d-b;
  if(arr[a][b+diff/2] == '.') cout << "UP";
  else if(arr[a+diff/2][b] == '.') cout << "LEFT";
  else if(arr[a+diff/2][d] == '.') cout << "RIGHT";
  else if(arr[a+diff][b+diff/2] == '.') cout << "DOWN";
    
  return 0;
}