#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

using ll = long long;
typedef pair<ll, ll> pll;

int N;
ll arr[100001];
vector<pll> tree;

pll update(int node, int st, int en, int idx, ll v) {
    if(en < idx || idx < st) return tree[node];
    if(st == en) return tree[node] = {v, st};
    int mid = (st+en)>>1;
    pll a = update(node*2, st, mid, idx, v);
    pll b = update(node*2+1, mid+1, en, idx, v);
    if(a.first > b.first) return tree[node] = a;
    else return tree[node] = b;
}

pll query(int node, int st, int en, int l, int r) {
    if(r < st || en < l) return {0, 0};
    if(l <= st && en <= r) return tree[node];
    int mid = (st+en)>>1;
    pll a = query(node*2, st, mid, l, r);
    pll b = query(node*2+1, mid+1, en, l, r);
    if(a.first > b.first) return a;
    else return b;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N;
    tree.resize(N*4);
    for(int a, i=0; i<N; i++) {
        cin >> a;
        update(1, 0, N-1, i, a);
    }
    int M; cin >> M;
    while(M--) {
        ll a, b, c; cin >> a >> b >> c;
        if(a == 1) {
            update(1, 0, N-1, b-1, c);
        } else {
            pll res = query(1, 0, N-1, b-1, c-1);
            pll Lres = query(1, 0, N-1, b-1, res.second-1);
            pll Rres = query(1, 0, N-1, res.second+1, c-1);
            cout << res.first + max(Lres.first, Rres.first) << '\n';
        }
    }

    return 0;
}