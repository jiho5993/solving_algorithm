#include <bits/stdc++.h>
using namespace std;

#define LOCAL_TEST

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

const int MAX = 500*500;
int arr[MAX + 1];
int res_t = 1e9, res_h = 0;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    int N = a * b;
    for (int i=0; i<N; i++) cin >> arr[i];

    for (int h=256; h>=0; h--) {
        int s1 = 0, s2 = 0;

        for (int i=0; i<N; i++) {
            if (arr[i] == h) continue;
            else if (arr[i] > h) s1 += (arr[i]-h);
            else s2 += (h-arr[i]);
        }
        
        if (s1 + c >= s2) {
            int t = s1*2 + s2;
            if (t < res_t) {
                res_t = t;
                res_h = h;
            }
        }
    }

    cout << res_t << ' ' << res_h << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
