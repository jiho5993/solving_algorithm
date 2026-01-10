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
int arr[21][21];
int res = 1e9;

int cal_stat(vector<int> t) {
    int s = 0;
    int sz = t.size();
    for (int i=0; i<sz; i++) {
        for (int j=i+1; j<sz; j++) {
            s += arr[t[i]][t[j]] + arr[t[j]][t[i]];
        }
    }
    return s;
}

void dfs(int n, vector<int> a, vector<int> b) {
    if (!a.empty() && !b.empty() && n == N+1) {
        int diff = abs(cal_stat(a) - cal_stat(b));
        res = min(res, diff);
        return;
    }
    if (n >= N+1) return;

    a.push_back(n);
    dfs(n+1, a, b);
    a.pop_back();
    
    b.push_back(n);
    dfs(n+1, a, b);
    b.pop_back();
}

void solve() {
    cin >> N;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(1, vector<int>(), vector<int>());
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
