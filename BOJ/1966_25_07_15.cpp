#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

void solve() {
    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        queue<pair<int, int> > qp;
        priority_queue<int> pq;

        for (int i=0; i<N; i++) {
            int a; cin >> a;
            qp.push({a, i});
            pq.push(a);
        }

        int res = 0;
        while (!pq.empty()) {
            int x = pq.top();
            while (qp.front().first != x) {
                qp.push(qp.front());
                qp.pop();
            }
            if (M == qp.front().second) {
                cout << res+1 << '\n';
                break;
            } else {
                qp.pop();
                pq.pop();
                res++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
