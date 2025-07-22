#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

unordered_set<string> us;

void solve() {
    int N, M; cin >> N >> M;
    for (int i=0; i<N; i++) {
        string s; cin >> s;
        string cur = "";
        for (auto i: s) {
            cur += i;
            us.insert(cur);
        }
    }

    int res = 0;
    while (M--) {
        string s; cin >> s;
        if (us.find(s) != us.end()) res++;
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
