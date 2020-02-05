#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int N;
bool visit[100001];
int parent[100001];
vector<vector<int> > arr(100001);

void dfs(int st) {
  visit[st] = 1;
  for(auto i:arr[st]) {
    if(!visit[i]) {
      parent[i] = st;
      dfs(i);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  cin >> N;
  for(int i=0; i<N; i++) {
    int a, b; cin >> a >> b;
    arr[a].pb(b);
    arr[b].pb(a);
  }
  dfs(1);
  for(int i=2; i<=N; i++) cout << parent[i] << '\n';

  return 0;
}