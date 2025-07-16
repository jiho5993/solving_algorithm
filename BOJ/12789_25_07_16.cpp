#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

stack<int> st;

void solve() {
    int N; cin >> N;

    int idx = 1;
    for (int i=0; i<N; i++) {
        int a; cin >> a;

        if (a == idx) idx++;
        else st.push(a);

        while (!st.empty() && st.top() == idx) {
            idx++;
            st.pop();
        }
    }

    st.empty() ? cout << "Nice" : cout << "Sad";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
