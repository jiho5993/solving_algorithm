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

int res[100001];
priority_queue<int, vector<int>, greater<int> > pq[200001];

void solve() {
    int N, M; cin >> N >> M;
    for (int i=0; i<N; i++) {
        int n; cin >> n;
        for (int j=0; j<n; j++) {
            int a; cin >> a;
            pq[a].push(i);
        }
    }

    for (int i=0; i<M; i++) {
        int a; cin >> a;
        if (pq[a].empty()) continue;
        else {
            int k = pq[a].top();
            res[k]++;
            pq[a].pop();
        }
    }

    for (int i=0; i<N; i++) cout << res[i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
