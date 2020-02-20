#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef struct SegTree {
  int size;
  vector<int> tree, lazy;
  SegTree(int N) {
    size = N;
    tree.resize(N*4);
    lazy.resize(N*4);
  }

  void update_lazy(int node, int st, int en) {
    if(lazy[node]) {
      tree[node] = (en-st+1)-tree[node];
      if(st != en) {
        lazy[node*2] = !lazy[node*2];
        lazy[node*2+1] = !lazy[node*2+1];
      }
      lazy[node] = 0;
    }
  }

  void update_tree(int left, int right) { update_tree(1, 1, size, left, right); }
  void update_tree(int node, int st, int en, int left, int right) {
    update_lazy(node, st, en);

    if(left > en || st > right) return;

    if(left <= st && en <= right) {
      tree[node] = (en-st+1)-tree[node];
      if(st != en) {
        lazy[node*2] = !lazy[node*2];
        lazy[node*2+1] = !lazy[node*2+1];
      }
      return;
    }

    int mid = (st+en)/2;
    update_tree(node*2, st, mid, left, right);
    update_tree(node*2+1, mid+1, en, left, right);
    tree[node] = tree[node*2] + tree[node*2+1];
  }

  int query(int left, int right) { return query(1, 1, size, left, right); }
  int query(int node, int st, int en, int left, int right) {
    update_lazy(node, st, en);

    if(left > en || st > right) return 0;
    if(left <= st && en <= right) return tree[node];

    int mid = (st+en)/2;
    return query(node*2, st, mid, left, right) + query(node*2+1, mid+1, en, left, right);
  }

} ST;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  int N, M; cin >> N >> M;
  ST tree(N);

  while(M--) {
    int a, b, c; cin >> a >> b >> c;
    if(a == 0) tree.update_tree(b, c);
    else cout << tree.query(b, c) << '\n';
  }

  return 0;
}