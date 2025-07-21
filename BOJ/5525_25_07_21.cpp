#include <bits/stdc++.h>
using namespace std;

#define LOCAL_TEST

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

void solve() {
    int N, M; cin >> N >> M;
    string s; cin >> s;

    int res = 0;
    for (int i=0; i<s.size()-1; i++) {
        if (s[i] == 'I' && s[i+1] == 'O') {
            int cnt = 0;
            while (s[i+1] == 'O' && s[i+2] == 'I') {
                cnt++;
                i += 2;
            }
            if (cnt >= N) res += (cnt - N + 1);
        }
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
