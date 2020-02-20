#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
ll arr[500001];

typedef struct SegTree {
  int size;
  vector<ll> tree, lazy;
  SegTree(int N) {
    size = N;
    tree.resize(N*4);
    lazy.resize(N*4);
  }

  ll init(int node, int st, int en) {
    if(st == en) return tree[node] = arr[st];

    int mid = (st+en)/2;
    return tree[node] = init(node*2, st, mid) ^ init(node*2+1, mid+1, en);
  }

  void update_lazy(int node, int st, int en) {
    if(lazy[node]) {
      tree[node] ^= lazy[node]*((en-st+1)%2);
      if(st != en) {
        lazy[node*2] ^= lazy[node];
        lazy[node*2+1] ^= lazy[node];
      }
      lazy[node] = 0;
    }
  }

  void update_tree(int left, int right, ll diff) { update_tree(1, 0, size-1, left, right, diff); }
  void update_tree(int node, int st, int en, int left, int right, ll diff) {
    update_lazy(node, st, en);

    if(left > en || st > right) return;

    if(left <= st && en <= right) {
      tree[node] ^= diff*((en-st+1)%2);
      if(st != en) {
        lazy[node*2] ^= diff;
			  lazy[node*2+1] ^= diff;
      }
      return;
    }
    int mid = (st+en)/2;
    update_tree(node*2, st, mid, left, right, diff);
    update_tree(node*2+1, mid+1, en, left, right, diff);
    tree[node] = tree[node*2] ^ tree[node*2+1];
  }

  ll query(int left, int right) { return query(1, 0, size-1, left, right); }
  ll query(int node, int st, int en, int left, int right) {
    update_lazy(node, st, en);

    if(left > en || st > right) return 0;
    if(left <= st && en <= right) return tree[node];

    int mid = (st+en)/2;
    return query(node*2, st, mid, left, right) ^ query(node*2+1, mid+1, en, left, right);
  }

} ST;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  int N, M; cin >> N;
  for(int i=0; i<N; i++) cin >> arr[i];
  ST tree(N);
  tree.init(1, 0, N-1);

  cin >> M;
  while(M--) {
    int a; cin >> a;
    if(a == 1) {
      ll b, c, d; cin >> b >> c >> d;
      if(b > c) swap(b, c);
      tree.update_tree(b, c, d);
    } else {
      ll b, c; cin >> b >> c;
      if(b > c) swap(b, c);
      cout << tree.query(b, c) << '\n';
    }
  }

  return 0;
}