#include <bits/stdc++.h>
using namespace std;

#define LOCAL_TEST

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int N;
vector<int> arr[100001];
int p[100001];

void dfs(int x) {
    for (auto n: arr[x]) {
        if (p[n] != 0) continue;
        p[n] = x;
        dfs(n);
    }
}

void solve() {
    cin >> N;
    for (int i=0; i<N-1; i++) {
        int a, b; cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    p[1] = -1;
    dfs(1);

    for (int i=2; i<=N; i++) cout << p[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
