#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int N, M;
int arr[10];
bool isused[10];

void dfs(int cnt, int res[10]) {
    if (cnt == M) {
        for (int i=0; i<cnt; i++) cout << res[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i=0; i<N; i++) {
        if (isused[i]) continue;
        res[cnt] = arr[i];
        isused[i] = true;
        dfs(cnt+1, res);
        isused[i] = false;
    }
}

void solve() {
    cin >> N >> M;
    for (int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);

    int res[10]={0,};
    dfs(0, res);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
