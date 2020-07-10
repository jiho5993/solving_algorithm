#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int arr[10005];

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N, M, rs=0; cin >> N >> M;
  for(int i=0; i<N; i++) cin >> arr[i];
  sort(arr, arr+N+1);
  int p=0;
  for(p=0; p<=N && arr[p]; p++);
  for(int i=0; i<p; i+=M) rs += abs(arr[i]*2);
  for(int i=N; i>p; i-=M) rs += abs(arr[i]*2);
  rs -= max(abs(arr[0]), abs(arr[N]));

  cout << rs;
  
  return 0;
}