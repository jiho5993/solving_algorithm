#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

string arr[1001];

bool cmp(string a, string b) {
  for(int i=0; a.size()<10; i++) a += a[i];
  for(int i=0; b.size()<10; i++) b += b[i];
  return a > b;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int K, N, mx=0; cin >> K >> N;
  for(int i=0; i<K; i++) {
    cin >> arr[i];
    mx = max(mx, stoi(arr[i]));
  }
  for(int i=K; i<N; i++) arr[i] = to_string(mx);
  sort(arr, arr+N+K, cmp);
  for(int i=0; i<N+K; i++) cout << arr[i];

  return 0;
}