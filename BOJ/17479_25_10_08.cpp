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
    int A, B, C; cin >> A >> B >> C;
    unordered_map<string, ll> as, bs;
    unordered_set<string> cs;
    for (int i=0; i<A; i++) {
        string s;
        ll a;
        cin >> s >> a;
        as.insert({s, a});
    }
    for (int i=0; i<B; i++) {
        string s;
        ll a;
        cin >> s >> a;
        bs.insert({s, a});
    }
    for (int i=0; i<C; i++) {
        string s; cin >> s;
        cs.insert(s);
    }

    int n; cin >> n;
    ll ap=0, bp=0, cc=0;
    while (n--) {
        string s; cin >> s;
        if (as.find(s) != as.end()) {
            ap += as[s];
        } else if (bs.find(s) != bs.end()) {
            bp += bs[s];
        } else {
            cc++;
        }
    }

    if ((ap < 20000 && bp > 0) || (ap + bp < 50000 && cc > 0) || cc >= 2) cout << "No";
    else cout << "Okay";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
