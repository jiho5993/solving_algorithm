#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int N, T, G;
bool visit[100001];

int bfs() {
  queue<pair<int, int> > qp;
  qp.push({N, 0});
  visit[N] = 1;
  while(!qp.empty()) {
    int tmp = qp.front().first;
    int cnt = qp.front().second;
    qp.pop();
    if(cnt > T) break;
    if(tmp == G) return cnt;
    int A = tmp+1;
    if(A <= 99999 && !visit[A]) {
      qp.push({A, cnt+1});
      visit[A] = 1;
    }
    int B = tmp*2, _B = tmp*2, digit = 1;
    if(B > 99999) continue;
    while(_B) {
      _B /= 10;
      digit *= 10;
    }
    B -= digit/10;
    if(B <= 99999 && !visit[B]) {
      qp.push({B, cnt+1});
      visit[B] = 1;
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  cin >> N >> T >> G;
  int ret = bfs();
  ret == -1 ? cout << "ANG" : cout << ret;
  
  return 0;
}