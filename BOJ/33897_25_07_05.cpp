#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

void solve() {
    int N; cin >> N;
    int mx = -1, res = 0;
    int cnt = 0, prev = -1;

    for (int i=0; i<N; i++) {
        int a; cin >> a;
        if (prev <= a) {
            cnt++;
        } else {
            res++;
            mx = max(mx, cnt);
            cnt = 1;
        }
        prev = a;
    }

    cout << res+1 << ' ' << max(mx, cnt);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
