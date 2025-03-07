#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int N, M;
vector<int> arr1[101];
vector<int> arr2[101];
bool visited[101];
int cnt = 0;
int d[101];

void dfs(int x, vector<int> arr[101]) {
    visited[x] = true;

    for (auto i: arr[x]) {
        if (visited[i]) continue;
        cnt++;
        dfs(i, arr);
    }
}

int find_bead(vector<int> arr[101]) {
    int res = 0;

    for (int x=1; x<=N; x++) {
        cnt = 0;
        memset(visited, 0, sizeof(bool) * 101);
        dfs(x, arr);
        if (cnt > (N-1)/2) res++;
    }

    return res;
}

void solve() {
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        arr1[a].push_back(b);
        arr2[b].push_back(a);
    }

    cout << find_bead(arr1) + find_bead(arr2);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
