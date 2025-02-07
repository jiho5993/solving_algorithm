#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;

    int res = 1, tmp = 1, m = 6;
    while (N > tmp) {
        tmp += m;
        res++;
        m += 6;
    }

    cout << res;

    return 0;
}
