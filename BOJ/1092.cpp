#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int N, M;
vector<int> crane, box;
int rs;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  cin >> N;
  for(int i=0; i<N; i++) {
    int a; cin >> a;
    crane.pb(a);
  }
  cin >> M;
  for(int i=0; i<M; i++) {
    int a; cin >> a;
    box.pb(a);
  }
  sort(all(crane), greater<int>());
  sort(all(box), greater<int>());
  if(crane[0] < box[0]) cout << "-1";
  else {
    while(box.size()) {
      int idx=0;
      for(int i=0; i<box.size(); i++) {
        if(idx == N) break;
        if(crane[idx] >= box[i]) {
          idx++;
          box.erase(box.begin()+i);
          i--;
        }
      }
      rs++;
    }
    cout << rs;
  }

  return 0;
}