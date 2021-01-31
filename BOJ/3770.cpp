#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
ll N, M, K;
ll tree[1001];

void update(int i) {
    for(; i<=M; i+=(i&-i)) tree[i]++;
}

ll query(int i) {
    ll s = 0;
    for(; i>0; i-=(i&-i)) s += tree[i];
    return s;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    int T; cin >> T;
    for(int TC=1; TC<=T; TC++) {
        memset(tree, 0, sizeof(tree));
        cin >> N >> M >> K;
        ll res=0;
        vector<pair<ll, ll> > r(K);
        for(int i=0; i<K; i++) cin >> r[i].first >> r[i].second;
        sort(all(r));
        for(auto i:r) {
            res += query(M)-query(i.second);
            update(i.second);
        }
        cout << "Test case " << TC << ": " <<  res << '\n';
    }

    return 0;
}