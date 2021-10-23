#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

using ll = long long;

ll foo(ll C, ll K) {
    ll d0 = C, d1 = K;
    ll x0 = 1, x1 = 0, q;

    while (d1 != 0) {
        q = d0 / d1;
        d0 = d0 - q*d1; swap(d0, d1);
        x0 = x0 - q*x1; swap(x0, x1);
    }

    if (d0 == 1)
        return x0 > 0 ? x0 : x0 + K;
    else
        return 0;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int T; cin >> T;
    while (T--) {
        ll K, C; cin >> K >> C;

        if (K == 1 && C == 1) {
            cout << 2 << '\n';
            continue;
        }
        if (C == 1) {
            if (K+1 > 1e9) {
                cout << "IMPOSSIBLE\n";
                continue;
            } else {
                cout << K+1 << '\n';
                continue;
            }
        }

        ll res = foo(C, K);
        if (res == 0) cout << "IMPOSSIBLE\n";
        else cout << res << '\n';
    }

    return 0;
}