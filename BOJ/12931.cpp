#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N, rs=0; cin >> N;
  int arr[51];
  for(int i=0; i<N; i++) cin >> arr[i];

  while(1) {
    bool chk = false;
    bool flag = false;
    for(int i=0; i<N; i++) {
      if(arr[i]&1) {
        flag = true;
        rs++;
        arr[i]--;
      }
      if(arr[i]) chk = true;
    }
    if(!chk) break;
    if(!flag) {
      for(int i=0; i<N; i++)
        arr[i] /= 2;
      rs++;
    }
  }
  cout << rs;
  
  return 0;
}