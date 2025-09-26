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
    string s;
    cin >> N >> s;

    int res = 0;
    for (int i=1; i<N; i++) {
        if (s[i-1] == ']' && s[i] == '[') continue;
        if (s[i-1] == '2' && s[i] == '2') res++;
        else if (s[i-1] == '5' && s[i] == '5') res++;
        res++;
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
