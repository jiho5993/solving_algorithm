#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
ll arr[5001];
int _1, _2, _3;
ll MAX = 3e9 + 1;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N; cin >> N;
  for(int i=0; i<N; i++) cin >> arr[i];
  sort(arr, arr+N);
  for(int i=0; i<N; i++) {
    if(i > 0 && arr[i] == arr[i-1]) continue;
    int lo=i+1, hi=N-1;
    while(lo < hi) {
      ll res = arr[i]+arr[lo]+arr[hi];
      if(llabs(res) < MAX) {
        MAX = llabs(res);
        _1 = i, _2 = lo, _3 = hi;
      }
      if(res < 0) lo++;
      else hi--;
    }
  }
  cout << arr[_1] << ' ' << arr[_2] << ' ' << arr[_3];
  
  return 0;
}