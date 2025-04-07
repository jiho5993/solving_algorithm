#include <bits/stdc++.h>
using namespace std;

#define LOCAL_TEST

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int N, K;
vector<pair<int, int> > arr;
vector<int> d;

void solve() {
    cin >> N >> K;
    int prev = -100;
    for (int i=0; i<N; i++) {
        int a; cin >> a;
        if (prev == a-1) {
            arr[arr.size()-1].second = a+1;
        } else {
            arr.push_back({a, a+1});
        }
        prev = a;
    }

    for (int i=1; i<arr.size(); i++) d.push_back(arr[i].first - arr[i-1].second);
    sort(d.begin(), d.end());

    int res = 0;
    if (arr.size() > K) {
        for (int i=0; i<arr.size()-K; i++)
            res += d[i];
    }
    for (int i=0; i<arr.size(); i++) res += (arr[i].second - arr[i].first);

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
