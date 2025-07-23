#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

string arr[10001];

void solve() {
    int N, M; cin >> N >> M;
    for (int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);

    int res = 0;
    while (M--) {
        string s; cin >> s;
        string f = *lower_bound(arr, arr+N, s);

        bool flag = false;
        for (int i=0; i<s.size(); i++) {
            if (s[i] != f[i]) {
                flag = true;
                break;
            }
        }

        if (!flag) res++;
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
