#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N;
ll arr[100001], tree[100001];

void update(int i) {
    while(i<=N+1) {
        tree[i]++;
        i+=(i&-i);
    }
}

ll query(int i) {
    ll ret=0;
    for(; i>0; i-=(i&-i)) ret += tree[i];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    int T; cin >> T;
    while(T--) {
        cin >> N;
        memset(arr, 0, sizeof(arr));
        memset(tree, 0, sizeof(tree));
        map<int, int> m;
        for(int i=0; i<N; i++) cin >> arr[i];
        for(int i=1; i<=N; i++) {
            int a; cin >> a;
            m[a] = i;
        }
        ll res=0;
        for(int i=0; i<N; i++) {
            ll idx = m[arr[i]];
            res += query(N)-query(idx);
            update(idx);
        }
        cout << res << '\n';
    }

    return 0;
}