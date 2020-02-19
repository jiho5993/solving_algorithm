#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int arr[1000001];

typedef struct SegTree {
  vector<int> tree;
  int size;
  SegTree(int N): size(N) {
    tree.resize(N*4);
  }

  void init(int node, int st, int en) {
    if(st == en) {
      tree[node] = arr[st];
      return;
    }

    int mid = (st+en)/2;
    init(node*2, st, mid);
    init(node*2+1, mid+1, en);
    tree[node] = max(tree[node*2], tree[node*2+1]);
  }

  int find(int left, int right) { return find(1, 0, size-1, left, right); }
  int find(int node, int st, int en, int left, int right) {
    if(en < left || right < st) return -1;
    if(left <= st && en <= right) return tree[node];

    int mid = (st+en)/2;
    return max(find(node*2, st, mid, left, right), find(node*2+1, mid+1, en, left, right));
  }

} ST;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  int N, M; cin >> N >> M;
  for(int i=0; i<N; i++) cin >> arr[i];
  ST tree(N);
  tree.init(1, 0, N-1);

  for(int i=M-1; i<N-M+1; i++) cout << tree.find(i-M+1, i+M-1) << ' ';

  return 0;
}