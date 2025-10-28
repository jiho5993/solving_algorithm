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

string N;
int K;
int res = -1;
bool dp[1000001][11];

void dfs(string tmp, int k) {
    dp[stoi(tmp)][k] = true;

    if (N.size() < 2) return;
    if (N.size() == 2 && (N[0] == '0' || N[1] == '0')) return;
    if (k == K) {
        res = max(res, stoi(tmp));
        return;
    }

    for (int i=0; i<tmp.size(); i++) {
        for (int j=i+1; j<tmp.size(); j++) {
            string n = tmp;
            swap(n[i], n[j]);

            if (dp[stoi(n)][k+1]) continue;

            dp[stoi(n)][k+1] = true;
            dfs(n, k+1);
        }
    }
}

void solve() {
    cin >> N >> K;

    dfs(N, 0);
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
