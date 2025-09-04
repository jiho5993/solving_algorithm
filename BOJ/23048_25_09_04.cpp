#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

#define MAX 500001

int N;
int res = 0;
int prime[MAX];

void eratos() {
    prime[1] = 1;
    res++;

    int tmp = 2;
    for (int i=2; i<=N; i++) {
        if (prime[i] != 0) continue;
        for (int j=i; j<=N; j+=i) prime[j] = tmp;
        res++;
        tmp++;
    }
}

void solve() {
    cin >> N;

    eratos();

    cout << res << '\n';
    for (int i=1; i<=N; i++) cout << prime[i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
