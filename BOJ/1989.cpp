#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int N;
ll arr[100001];
tuple<ll, ll, ll> res={-1, -1, -1};
vector<pll> tree;

pll init(int node, int st, int en) {
    if(st == en) return tree[node] = {st, arr[st]};
    int mid = (st+en)>>1;
    pll ret1 = init(node*2, st, mid);
    pll ret2 = init(node*2+1, mid+1, en);
    return tree[node]={arr[ret1.first]<arr[ret2.first]?ret1.first:ret2.first, ret1.second+ret2.second};
}

pll query(int node, int st, int en, int l, int r) {
    if(r < st || en < l) return {-1, 0};
    if(l <= st && en <= r) return tree[node];
    int mid = (st+en)>>1;
    pll ret1 = query(node*2, st, mid, l, r);
    pll ret2 = query(node*2+1, mid+1, en, l, r);
    if(ret1.first == -1) return ret2;
    else if(ret2.first == -1) return ret1;
    else return {arr[ret1.first] < arr[ret2.first] ? ret1.first : ret2.first, ret1.second+ret2.second};
}

void foo(int l, int r) {
    if(l > r) return;
    pll ret = query(1, 0, N-1, l, r);
    ll s, i, j;
    tie(s, i, j) = res;
    ll _s = ret.second*arr[ret.first];
    if(s < _s) res = {_s, l+1, r+1};
    foo(l, ret.first-1);
    foo(ret.first+1, r);
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N;
    tree.resize(N*4);
    for(int i=0; i<N; i++) cin >> arr[i];
    init(1, 0, N-1);
    foo(0, N-1);
    ll s, i, j;
    tie(s, i, j) = res;
    cout << s << '\n' << i << ' ' << j;

    return 0;
}