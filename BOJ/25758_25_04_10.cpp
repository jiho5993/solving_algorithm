#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int N;
string arr[100001];
set<char> res;

void solve() {
    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];

    for (char c='A'; c<='Z'; c++) {
        int cnt = 0;
        for (int i=0; i<N; i++) {
            cnt += arr[i][0] == c;
        }

        if (cnt == 1) {
            for (int i=0; i<N; i++) {
                if (arr[i][0] == c) continue;
                res.insert(max(c, arr[i][1]));
            }
        } else if (cnt > 1) {
            for (int i=0; i<N; i++) {
                res.insert(max(c, arr[i][1]));
            }
        }
    }

    cout << res.size() << '\n';
    for (auto i: res) cout << i << ' ';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
