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

pair<int, int> arr[200001];

void solve() {
    int N; cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i].first;
    for (int i=0; i<N; i++) cin >> arr[i].second;

    sort(arr, arr+N);

    ll res = 0, w = 0;
    for (int i=N-1; i>=0; i--) {
        w += arr[i].second;
        res = max(res, w*arr[i].first);
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
