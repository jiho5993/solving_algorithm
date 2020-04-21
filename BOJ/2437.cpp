#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int arr[1001];

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N, ret=1; cin >> N;
  for(int i=0; i<N; i++) cin >> arr[i];
  sort(arr, arr+N);
  for(int i=0; i<N; i++) {
    if(ret < arr[i]) break;
    ret += arr[i];
  }
  cout << ret;
  
  return 0;
}