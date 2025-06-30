#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

bool arr[101];

void solve() {
    int N; cin >> N;
    for (int i=1; i<=N; i++) cin >> arr[i];
    int M; cin >> M;
    while (M--) {
        int a, b; cin >> a >> b;
        if (a == 1) {
            int cur = b;
            while (cur <= N) {
                arr[cur] = !arr[cur];
                cur += b;
            }
        } else {
            int l = b-1, r = b+1;
            arr[b] = !arr[b];
            while (l >= 1 && r <= N) {
                if (arr[l] != arr[r]) break;
                arr[l] = !arr[l];
                arr[r] = !arr[r];
                l--; r++;
            }
        }
    }

    
    for (int i=1; i<=N; i++) {
        cout << arr[i] << ' ';
        if (i % 20 == 0) cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
