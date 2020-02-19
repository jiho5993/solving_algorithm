#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
ll arr[1000001];

typedef struct SegTree {
  vector<ll> tree;
  int size;
  SegTree(int N): size(N) {
    tree.resize(N*4);
  }

  void update(int idx, ll diff) { update(1, 0, size-1, idx, diff); }
  void update(int node, int st, int en, int idx, ll diff) {
    if(!(st <= idx && idx <= en)) return;

    tree[node] += diff;

    if(st != en) {
      int mid = (st+en)/2;
      update(node*2, st, mid, idx, diff);
      update(node*2+1, mid+1, en, idx, diff);
    }
  }

  ll sum(int left, int right) { return sum(1, 0, size-1, left, right); }
  ll sum(int node, int st, int en, int left, int right) {
    if(en < left || right < st) return 0;
    if(left <= st && en <= right) return tree[node];

    int mid = (st+en)/2;
    return sum(node*2, st, mid, left, right) + sum(node*2+1, mid+1, en, left, right);
  }

} ST;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  int N, Q; cin >> N >> Q;
  ST tree(N);

  while(Q--) {
    int a, b, c; cin >> a >> b >> c;
    if(a == 1) {
      ll diff = c-arr[b-1];
      arr[b-1] = c;
      tree.update(b-1, c);
    } else cout << tree.sum(b-1, c-1) << '\n';
  }

  return 0;
}