#include <bits/stdc++.h>
using namespace std;

#define LOCAL_TEST

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

string arr[10001];

void solve() {
    int N, M; cin >> N >> M;
    for (int i=0; i<N; i++) cin >> arr[i];

    int res = 0;
    for (int i=0; i<M; i++) {
        int v[30]={0,};
        for (int j=0; j<N; j++) v[arr[j][i]-'A']++;

        char c;
        int mx = -1;
        for (int j=0; j<30; j++) {
            if (mx < v[j]) {
                mx = v[j];
                c = j+'A';
            }
        }

        for (int j=0; j<N; j++) {
            if (arr[j][i] == c) continue;
            res++;
        }
        cout << c;
    }
    cout << '\n' << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
