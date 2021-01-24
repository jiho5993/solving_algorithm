#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1000001;
int N, arr[MAX];
ll res=0;
vector<int> tree;

int init(int node, int st, int en) {
    if(st == en) return tree[node] = st;
    int mid = (st+en)>>1;
    int ret1 = init(node*2, st, mid);
    int ret2 = init(node*2+1, mid+1, en);
    return tree[node] = arr[ret1] < arr[ret2] ? ret1 : ret2;
}

int query(int node, int st, int en, int l, int r) {
    if(r < st || en < l) return -1;
    if(l <= st && en <= r) return tree[node];
    int mid = (st+en)>>1;
    int ret1 = query(node*2, st, mid, l, r);
    int ret2 = query(node*2+1, mid+1, en, l, r);
    if(ret1 == -1) return ret2;
    else if(ret2 == -1) return ret1;
    else return arr[ret1] < arr[ret2] ? ret1 : ret2;
}

void foo(int l, int r) {
    if(l > r) return;
    int ret = query(1, 0, N-1, l, r);
    res = max(res, (ll)arr[ret]*(r-l+1));
    foo(l, ret-1);
    foo(ret+1, r);
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N;
    tree.resize(N*4);
    for(int i=0; i<N; i++) cin >> arr[i];
    init(1, 0, N-1);
    foo(0, N-1);
    cout << res;

    return 0;
}