#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int idx = 0;
char res[1000001];

void solve() {
    string s, b; cin >> s >> b;

    int bsz = b.size();

    for (int i=0; i<s.size(); i++) {
        res[idx++] = s[i];
        if (s[i] == b[bsz-1]) {
            bool flag = true;
            for (int j=0; j<bsz; j++) {
                if (res[idx-j-1] != b[bsz-j-1]) {
                    flag = false;
                    break;
                }
            }
            if (flag) idx -= bsz;
        }
    }

    if (idx == 0) cout << "FRULA";
    else {
        res[idx] = '\0';
        cout << res;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
