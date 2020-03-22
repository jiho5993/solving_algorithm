#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

struct sticker {
  int r, c;
  bool info[11][11];
};

int N, M, K, ret=0;
bool arr[41][41];
sticker tmp;

void rotate() {
  bool sv[11][11];
  int r = tmp.r, c = tmp.c;
  for(int i=0; i<r; i++)
    for(int j=0; j<c; j++)
      sv[i][j] = tmp.info[i][j];
  
  for(int i=0; i<c; i++)
    for(int j=0; j<r; j++)
      tmp.info[i][j] = sv[r-j-1][i];

  swap(tmp.r, tmp.c);
}

bool chk() {
  int r = tmp.r, c = tmp.c;
  for(int y=0; y<=N-r; y++) {
    for(int x=0; x<=M-c; x++) {
      bool flag = true;
      for(int i=0; i<r; i++) {
        if(!flag) break;
        for(int j=0; j<c; j++) {
          if(arr[y+i][x+j] && tmp.info[i][j]) {
            flag = false;
            break;
          }
        }
      }
      if(!flag) continue;
      for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
          if(tmp.info[i][j])
            arr[y+i][x+j] = tmp.info[i][j];
        }
      }
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  cin >> N >> M >> K;
  while(K--) {
    int r, c; cin >> r >> c;
    tmp.r = r, tmp.c = c;
    memset(tmp.info, 0, sizeof(tmp.info));
    for(int i=0; i<r; i++)
      for(int j=0; j<c; j++)
        cin >> tmp.info[i][j];
    for(int i=0; i<4; i++) {
      if(chk()) break;
      rotate();
    }
  }

  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      ret += arr[i][j];

  cout << ret;

  return 0;
}