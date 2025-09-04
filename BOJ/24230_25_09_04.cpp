#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int N;
int arr[200001];
vector<int> adj[200001];

int dfs(int prev, int cur) {
    int ret = 0;
    for (int n: adj[cur]) {
        if (n == prev) continue;
        if (arr[cur] != arr[n]) ret++;
        ret += dfs(cur, n);
    }
    return ret;
}

void solve() {
    cin >> N;
    for (int i=1; i<=N; i++) cin >> arr[i];
    for (int i=0; i<N-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int res = dfs(0, 1);
    if (arr[1] != 0) res++;
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
