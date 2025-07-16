#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int arr[100001];

void solve() {
    int N, M; cin >> N >> M;
    int s = 0, mx = -1;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
        s += arr[i];
        mx = max(mx, arr[i]);
    }

    int l = mx, r = s;
    while (l <= r) {
        int mid = (l+r)/2;
        
        int tmp = 0, cnt = 0;
        for (int i=0; i<N; i++) {
            if (tmp + arr[i] > mid) {
                tmp = 0;
                cnt++;
            }
            tmp += arr[i];
        }
        if (tmp > 0) cnt++;

        if (cnt <= M) r = mid-1;
        else l = mid+1;
    }

    cout << l;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
