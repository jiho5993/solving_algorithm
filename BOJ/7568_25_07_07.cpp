#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int arr[51][2];

void solve() {
    int N; cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i][0] >> arr[i][1];

    for (int i=0; i<N; i++) {
        int res = 1;
        for (int j=0; j<N; j++) {
            if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]) {
                res++;
            }
        }
        cout << res << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
