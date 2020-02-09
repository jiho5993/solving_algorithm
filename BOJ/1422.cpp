#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

#define MAX 1000000000
typedef long long ll;
int arr[1001];

bool cmp(int a, int b) {
  int x=MAX, y=MAX;
  while(!(a/x)) x /= 10;
  while(!(b/y)) y /= 10;
  return (ll)a * (ll)y * (ll)10 + (ll)b > (ll)b * (ll)x * (ll)10 + (ll)a;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int K, N, mx=0; cin >> K >> N;
  N -= K;
  for(int i=0; i<K; i++) {
    cin >> arr[i];
    mx = max(mx, arr[i]);
  }
  sort(arr, arr+K, cmp);
  for(int i=0; i<K; i++) {
    cout << arr[i];
    if(mx == arr[i] && N > 0)
      while(N--) cout << arr[i];
  }
  
  return 0;
}