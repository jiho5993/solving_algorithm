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

void solve() {
    int N;
    int st[2];
    vector<pii> target;
    
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int a; cin >> a;
            if (a == 2) {
                st[0] = i;
                st[1] = j;
            } else if (a == 1) {
                target.push_back({i, j});
            }
        }
    }

    for (pii t: target) {
        if ((t.first + t.second)%2 != (st[0]+st[1])%2) {
            cout << "Shorei";
            return;
        }
    }

    int res = 1e9;
    do {
        int x = st[0], y = st[1];
        int time = 0;
        for (pii t: target) {
            int dist = max(abs(t.first-x), abs(t.second-y));
            time += dist;
            x = t.first;
            y = t.second;
        }
        res = min(res, time);
    } while(next_permutation(target.begin(), target.end()));

    cout << "Undertaker\n" << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
