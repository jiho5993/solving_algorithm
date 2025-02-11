#include <bits/stdc++.h>
using namespace std;

bool arr[100001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;

    arr[1] = true;
    for (int i=2; i*i<=100000; i++) {
        if (arr[i]) continue;
        for (int j=i*i; j<=100000; j+=i) arr[j] = true;
    }

    while (T--) {
        int N; cin >> N;

        int idx = 2;
        while (N > 1) {
            if (arr[idx]) {
                idx++;
                continue;
            }

            int res = 0;
            while (N%idx == 0) {
                res++;
                N /= idx;
            }
            if (res > 0) {
                cout << idx << ' ' << res << '\n';
            }
            idx++;
        }
    }

    return 0;
}
