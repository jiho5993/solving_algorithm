#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

#define ll long long

ll arr[100001], arr2[100001];

void solve() {
    int N; cin >> N;
    for (int i=0; i<N-1; i++) cin >> arr[i];
    for (int i=0; i<N; i++) cin >> arr2[i];

    int idx = 1;
    ll cur = arr2[0];
    ll res = 0;
    while (idx < N) {
        ll d = 0;
        while (1) {
            d += arr[idx-1];
            idx++;
            if (cur > arr2[idx-1]) break;
        }

        res += cur * d;
        cur = arr2[idx-1];
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
