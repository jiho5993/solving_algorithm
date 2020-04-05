#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int p[201], arr[1001];

int find(int u) {
  if(p[u] == u) return u;
  return p[u] = find(p[u]);
}

void merge(int u, int v) {
  u = find(u), v = find(v);
  if(u != v) p[u] = v;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N, M; cin >> N >> M;
  for(int i=1; i<=N; i++) p[i] = i;
  for(int i=0; i<N*N; i++) {
    int a; cin >> a;
    if(a) merge(i/N+1, i%N+1);
  }
  for(int i=0; i<M; i++) cin >> arr[i];
  for(int i=1; i<M; i++) {
    if(find(arr[i-1]) != find(arr[i])) {
      cout << "NO";
      return 0;
    }
  }
  
  cout << "YES";
  
  return 0;
}