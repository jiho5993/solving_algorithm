#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

struct info {
  int y, x1, x2;
} arr[101];

bool cmp(info a, info b) { return a.y > b.y; }

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N; cin >> N;
  for(int i=0; i<N; i++) {
    int y, x1, x2; cin >> y >> x1 >> x2;
    arr[i] = {y, x1, x2-1};
  }
  sort(arr, arr+N, cmp);
  int ret=0;
  for(int i=0; i<N; i++) {
    ret += (2*arr[i].y);
    int x1=arr[i].x1, x2=arr[i].x2;
    for(int j=i+1; j<N; j++) {
      if(arr[j].x1 <= x1 && x1 <= arr[j].x2) {
        ret -= arr[j].y;
        break;
      }
    }
    for(int j=i+1; j<N; j++) {
      if(arr[j].x1 <= x2 && x2 <= arr[j].x2) {
        ret -= arr[j].y;
        break;
      }
    }
  }
  cout << ret;
  
  return 0;
}