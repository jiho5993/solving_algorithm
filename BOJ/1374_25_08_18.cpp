#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

pair<int, int> arr[100001];
priority_queue<int, vector<int>, greater<int> > pq;

void solve() {
    int N; cin >> N;
    for (int i=0; i<N; i++) {
        int a, b, c; cin >> a >> b >> c;
        arr[i] = {b, c};
    }

    sort(arr, arr+N);

    int res = -1;
    for (int i=0; i<N; i++) {
        res = max(res, (int)pq.size());
        while (!pq.empty() && pq.top() <= arr[i].first) pq.pop();
        pq.push(arr[i].second);
    }

    res = max(res, (int)pq.size());

    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
