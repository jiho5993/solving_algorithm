#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

#define MAX 1000000000
typedef long long ll;
ll A, B;

int bfs() {
  map<ll, bool> m;
  queue<pair<ll, int> > q;
  q.push({A, 0});
  m[A] = 1;
  while(!q.empty()) {
    ll tmp = q.front().first;
    int cnt = q.front().second;
    q.pop();
    if(tmp == B) return cnt+1;
    if(!m[tmp*2] && tmp*2 <= MAX) {
      q.push({tmp*2, cnt+1});
      m[tmp*2] = 1;
    }
    if(!m[tmp*10 + 1] && tmp*10 + 1 <= MAX) {
      q.push({tmp*10 + 1, cnt+1});
      m[tmp*10 + 1] = 1;
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  cin >> A >> B;
  cout << bfs();

  return 0;
}