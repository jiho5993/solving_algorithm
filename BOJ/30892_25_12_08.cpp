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

ll arr[200001];
stack<ll> st;

void solve() {
    ll N, K, T; cin >> N >> K >> T;
    for (int i=0; i<N; i++) cin >> arr[i];

    sort(arr, arr+N);

    int idx = 0;
    while (K--) {
        while (idx < N && arr[idx] < T) {
            st.push(arr[idx++]);
        }
        if (st.empty()) continue;
        T += st.top();
        st.pop();
    }

    cout << T;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
