#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr
#define ll long long
#define pii pair<int, int>

void solve() {
    int A, B, C, D; cin >> A >> B >> C >> D;

    if (A + B <= D && C <= D) cout << "~.~";
    else if (A + B <= D && C > D) cout << "Shuttle";
    else if (A + B > D && C <= D) cout << "Walk";
    else cout << "T.T";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
