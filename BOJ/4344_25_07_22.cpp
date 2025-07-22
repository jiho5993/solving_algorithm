#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

void solve() {
    int T; cin >> T;
    while (T--) {
        int arr[1001];
        int N; cin >> N;
        float avg = 0;
        for (int i=0; i<N; i++) {
            cin >> arr[i];
            avg += arr[i];
        }
        avg /= N;

        float cnt = 0;
        for (int i=0; i<N; i++) {
            if (arr[i] > avg) {
                cnt++;
            }
        }

        cout << fixed;
        cout.precision(3);
        cout << cnt/float(N)*100 << '%' << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
