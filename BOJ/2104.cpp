#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
int N;
ll arr[100001], res=0;
vector<pll> tree;

pll init(int node, int st, int en) {
    if(st == en) return tree[node] = {arr[st], st};
    int mid = (st+en)>>1;
    pll res1 = init(node*2, st, mid);
    pll res2 = init(node*2+1, mid+1, en);
    tree[node].first = res1.first+res2.first;
    tree[node].second = arr[res1.second] < arr[res2.second] ? res1.second : res2.second;
    return tree[node];
}

pll query(int node, int st, int en, int l, int r) {
    if(r < st || en < l) return {0, -1};
    if(l <= st && en <= r) return tree[node];
    int mid = (st+en)>>1;
    pll res1 = query(node*2, st, mid, l, r);
    pll res2 = query(node*2+1, mid+1, en, l, r);
    if(res1.second == -1) return res2;
    else if(res2.second == -1) return res1;
    else return {res1.first+res2.first, arr[res1.second] < arr[res2.second] ? res1.second : res2.second};
}

void foo(int l, int r) {
    if(l > r) return;
    pll ret = query(1, 0, N-1, l, r);
    res = max(res, arr[ret.second]*ret.first);
    foo(l, ret.second-1);
    foo(ret.second+1, r);
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