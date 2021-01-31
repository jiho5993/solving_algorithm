#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
int N, M;
ll tree[2001];

void update(int i) {
    for(; i<=N; i+=(i&-i)) tree[i]++;
}

ll query(int i) {
    ll s = 0;
    for(; i>0; i-=(i&-i)) s += tree[i];
    return s;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N >> M;
    ll res=0;
    vector<pair<ll, ll> > arr(M);
    for(int i=0; i<M; i++) cin >> arr[i].first >> arr[i].second;
    sort(all(arr));
    for(int i=0; i<M; i++) {
        res += query(N)-query(arr[i].second);
        update(arr[i].second);
    }
    cout << res;

    return 0;
}