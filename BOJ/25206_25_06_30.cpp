#include <bits/stdc++.h>
using namespace std;

#define LOCAL_TEST

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

unordered_map<string, double> m, g = {
    {"A+", 4.5},
    {"A0", 4.0},
    {"B+", 3.5},
    {"B0", 3.0},
    {"C+", 2.5},
    {"C0", 2.0},
    {"D+", 1.5},
    {"D0", 1.0},
    {"F", 0},
};

void solve() {
    double s1 = 0, s2 = 0;
    for (int i=0; i<20; i++) {
        string a, c;
        double b;
        cin >> a >> b >> c;

        if (c == "P") continue;

        s1 += b * g[c];
        s2 += b;
    }

    cout << s1 / s2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
