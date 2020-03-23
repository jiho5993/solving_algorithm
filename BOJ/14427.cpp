#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int N, M;
int arr[100001];

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  cin >> N;
  set<pair<int, int> > S;
  for(int i=1; i<=N; i++) {
    cin >> arr[i];
    S.insert({arr[i], i});
  }
  cin >> M;
  while(M--) {
    int q; cin >> q;
    if(q == 1) {
      int a, b; cin >> a >> b;
      S.erase({arr[a], a});
      arr[a] = b;
      S.insert({arr[a], a});
    } else {
      auto ret = *S.begin();
      cout << ret.second << '\n';
    }
  }

  return 0;
}