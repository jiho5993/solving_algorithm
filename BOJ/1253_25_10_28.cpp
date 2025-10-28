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

int N;
ll arr[2001];

void solve() {
    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);

    int res = 0;
    for (int i=0; i<N; i++) {
        ll tmp = arr[i];

        int l=0, r=N-1;
        while (l < r) {
            if (l == i) {
                l++;
                continue;
            }
            if (r == i) {
                r--;
                continue;
            }

            ll s = arr[l]+arr[r];
            if (s == tmp) {
                res++;
                break;
            } else if (s < tmp) {
                l++;
            } else {
                r--;
            }
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
