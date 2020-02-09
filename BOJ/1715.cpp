#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N, rs=0; cin >> N;
  priority_queue<int, vector<int>, greater<int> > pq;
  for(int i=0; i<N; i++) {
    int a; cin >> a;
    pq.push(a);
  }
  if(pq.size() == 1) cout << "0";
  else {
    while(1) {
      int a = pq.top();
      pq.pop();
      int b = pq.top();
      pq.pop();
      rs += (a+b);
      if(pq.empty()) break;
      pq.push(a+b);
    }
    cout << rs;
  }

  return 0;
}