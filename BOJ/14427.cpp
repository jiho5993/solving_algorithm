#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll arr[100001], tree[100001*4];

ll init(int node, int st, int en) {
    if(st == en) return tree[node] = arr[st];
    int mid = (st+en)/2;
    return tree[node] = min(init(node*2, st, mid), init(node*2+1, mid+1, en));
}

ll update(int node, int st, int en, int idx, ll val) {
    if(!(st <= idx && idx <= en)) return tree[node];
    if(st == en) return tree[node] = val;
    int mid = (st+en)/2;
    return tree[node] = min(update(node*2, st, mid, idx, val), update(node*2+1, mid+1, en, idx, val));
}

ll find_min(int node, int st, int en, int left, int right) {
    if(st > right || en < left) return 2e9;
    if(left <= st && en <= right) return tree[node];
    int mid = (st+en)/2;
    return min(find_min(node*2, st, mid, left, right), find_min(node*2+1, mid+1, en, left, right));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    init(1, 0, n-1);
    cin >> m;
    while(m--) {
        cin.ignore();
        int query; cin >> query;
        if(query == 1) {
            int i, v; cin >> i >> v;
            arr[i-1] = v;
            update(1, 0, n-1, i-1, v);
        } else {
            ll val = find_min(1, 0, n-1, 0, n-1);
            for(int i=0; i<n; i++) {
                if(val == arr[i]) {
                    cout << i+1 << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}