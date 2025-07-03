#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

#define t_type tuple<double, int, string>

t_type arr[31];

void solve() {
    int N; cin >> N;
    for (int i=0; i<N; i++) {
        string s;
        int a, b, c;
        cin >> s >> a >> b >> c;

        arr[i] = {floor((a*a*a)/(c*(b+1))), c, s};
    }

    sort(arr, arr+N, [](t_type a, t_type b) {
        double a1, a2;
        int b1, b2;
        string c1, c2;
        tie(a1, b1, c1) = a;
        tie(a2, b2, c2) = b;

        if (a1 == a2) {
            if (b1 == b2) {
                return c1 < c2;
            }
            return b1 < b2;
        }
        return a1 > a2;
    });

    cout << get<2>(arr[1]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
