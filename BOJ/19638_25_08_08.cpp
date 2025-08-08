#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

#define ll long long

priority_queue<ll> pq;

void solve() {
    ll N, H, T; cin >> N >> H >> T;
    for (int i=0; i<N; i++) {
        ll a; cin >> a;
        pq.push(a);
    }

    int t;
    for (t=0; t<T; t++) {
        int cur = pq.top();
        if (cur < H) break;
        if (cur == 1) break;

        pq.pop();
        pq.push(cur / 2);
    }

    if (pq.top() >= H) cout << "NO\n" << pq.top();
    else cout << "YES\n" << t;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
