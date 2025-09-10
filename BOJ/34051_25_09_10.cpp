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
    int N; cin >> N;
    string s; cin >> s;

    if (N == 1) {
        cout << s;
        return;
    }

    string res = s;
    for (int i=0; i<N-1; i++) {
        char c = *max_element(s.begin()+i+1, s.end());
        if (c <= s[i]) continue;

        for (int j=i+1; j<N; j++) {
            if (c != s[j]) continue;
            
            string tmp = s;
            reverse(tmp.begin()+i, tmp.begin()+j+1);
            if (res < tmp) res = tmp;
        }
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
};
