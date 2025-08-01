#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int arr[200001];
int cnt[200001];

void solve() {
    int N, M; cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        arr[a]++;
    }

    for (int i=1; i<=N; i++) cnt[arr[i]]++;

    long long res = 0;
    for (int i=0; i<=200000; i++) {
        while (cnt[i] > 1) {
            int s = cnt[i]/2;
            res += s;
            cnt[i+1] += s;
            cnt[i] -= s;
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
