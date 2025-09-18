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

int N, M;
bool arr[21][21];
bool visited[21];
ll res = 0;

bool check(vector<int> used, int t) {
    for (int i: used) {
        if (arr[i][t] || arr[t][i]) {
            return true;
        }
    }

    return false;
}

void dfs(int idx, vector<int> used) {
    res++;

    for (int i=idx; i<=N; i++) {
        if (visited[i]) continue;
        if (check(used, i)) continue;

        used.push_back(i);
        visited[i] = true;
        dfs(i, used);
        visited[i] = false;
        used.pop_back();
    }
}

void solve() {
    int T; cin >> T;
    for (int tc=1; tc<=T; tc++) {
        res = 0;
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));

        cin >> N >> M;
        for (int i=0; i<M; i++) {
            int a, b; cin >> a >> b;
            arr[a][b] = arr[b][a] = true;
        }

        dfs(1, vector<int>());

        cout << "#" << tc << ' ' << res << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
