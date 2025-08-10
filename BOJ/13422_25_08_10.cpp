#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

#define ll long long

int N, M, K;
int arr[100001];

void solve() {
    int T; cin >> T;
    while (T--) {
        memset(arr, 0, sizeof(arr));
        cin >> N >> M >> K;

        ll s = 0;
        for (int i=0, cnt=0; i<N; i++) {
            cin >> arr[i];
            if (cnt++ < M) s += arr[i];
        }

        if (N == M && s < K) {
            cout << 1 << '\n';
            continue;
        }

        int res = 0;
        for (int i=M; i<N+M-1; i++) {
            if (s < K) res++;
            s -= arr[i-M];
            if (i >= N) s += arr[i%N];
            else s += arr[i];
        }

        if (s < K) res++;
        cout << res << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
