#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef pair<int, int> pii;
pii jewel[300001];
int bag[300001];

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N, K; cin >> N >> K;
  for(int i=0; i<N; i++) {
    int a, b; cin >> a >> b;
    jewel[i] = {a, b};
  }
  for(int i=0; i<K; i++) cin >> bag[i];
  sort(jewel, jewel+N);
  sort(bag, bag+K);
  long long rs=0;
  priority_queue<int> pq;
  for(int i=0, j=0; i<K; i++) {
    while(j < N && jewel[j].first <= bag[i])
      pq.push(jewel[j++].second);
    if(!pq.empty()) {
      rs += pq.top();
      pq.pop();
    }
  }
  cout << rs;

  return 0;
}