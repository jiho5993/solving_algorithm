#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
int N, M;
ll arr[100005];

struct num {
  ll oe[2]={0, 0};
};

num init(vector<num> &tree, int node, int st, int en) {
  if(st == en) {
    tree[node].oe[arr[st]%2]++;
    return tree[node];
  }

  int mid = (st+en)/2;
  num tmp1 = init(tree, node*2, st, mid), tmp2 = init(tree, node*2+1, mid+1, en);
  tree[node].oe[0] = tmp1.oe[0]+tmp2.oe[0];
  tree[node].oe[1] = tmp1.oe[1]+tmp2.oe[1];
  return tree[node];
}

void update(vector<num> &tree, int node, int st, int en, int idx, int q) {
  if(!(st <= idx && idx <= en)) return;

  tree[node].oe[q]++;
  tree[node].oe[!q]--;
  
  if(st != en) {
    int mid = (st+en)/2;
    update(tree, node*2, st, mid, idx, q);
    update(tree, node*2+1, mid+1, en, idx, q);
  }
}

ll find(vector<num> &tree, int node, int st, int en, int left, int right, int q) {
  if(en < left || right < st) return 0;
  if(left <= st && en <= right) return tree[node].oe[q];
  
  int mid = (st+en)/2;
  return find(tree, node*2, st, mid, left, right, q) + find(tree, node*2+1, mid+1, en, left, right, q);
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++) cin >> arr[i];
  vector<num> tree(N*4);
  init(tree, 1, 0, N-1);

  cin >> M;
  for(int i=0; i<M; i++) {
    cin.ignore();
    ll a, b, c; cin >> a >> b >> c;
    if(a == 1 && c%2 != arr[b-1]%2) {
      arr[b-1] = c;
      update(tree, 1, 0, N-1, b-1, c%2);
    }
    if(a == 2) cout << find(tree, 1, 0, N-1, b-1, c-1, 0) << '\n';
    if(a == 3) cout << find(tree, 1, 0, N-1, b-1, c-1, 1) << '\n';
  }

  return 0;
}