#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
ll arr[100001];

typedef struct SegTree {
  vector<int> tree;
  int size;
  SegTree(int N): size(N) {
    tree.resize(N*4);
  }

  int init(int node, int st, int en) {
    if(st == en) {
      if(arr[st] == 0) return tree[node] = 0;
      else if(arr[st] > 0) return tree[node] = 1;
      else return tree[node] = -1;
    }

    int mid = (st+en)/2;
    return tree[node] = init(node*2, st, mid) * init(node*2+1, mid+1, en);
  }

  void update(int idx, int q) { update(1, 0, size-1, idx, q); }
  void update(int node, int st, int en, int idx, int q) {
    if(!(st <= idx && idx <= en)) return;

    if(st == en) {
      tree[node] = q;
      return;
    }

    int mid = (st+en)/2;
    update(node*2, st, mid, idx, q);
    update(node*2+1, mid+1, en, idx, q);
    tree[node] = tree[node*2] * tree[node*2+1];
  }

  int find(int left, int right) { return find(1, 0, size-1, left, right); }
  int find(int node, int st, int en, int left, int right) {
    if(en < left || st > right) return 1;
    if(left <= st && en <= right) return tree[node];

    int mid = (st+en)/2;
    return find(node*2, st, mid, left, right) * find(node*2+1, mid+1, en, left, right);
  }

} ST;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  int N, K;
  while(cin >> N >> K) {
    memset(arr, 0, sizeof(arr));
    for(int i=0; i<N; i++) cin >> arr[i];
    ST tree(N);
    tree.init(1, 0, N-1);

    for(int i=0; i<K; i++) {
      char cmd;
      int a, b;
      cin >> cmd >> a >> b;
      if(cmd == 'C') {
        int val;
        if(b == 0) val = 0;
        else if(b > 0) val = 1;
        else val = -1;
        arr[a-1] = b;
        tree.update(a-1, val);
      } else {
        int ret = tree.find(a-1, b-1);
        if(ret == 0) cout << "0";
        else if(ret > 0) cout << "+";
        else cout << "-";
      }
    }
    cout << '\n';
  }

  return 0;
}