#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;

    int res_5 = N/5;
    while (1) {
        int tmp = N - (res_5 * 5);
        if (res_5 < 0) {
            cout << -1;
            return 0;
        }
        if (tmp % 3 == 0) {
            cout << (tmp / 3) + res_5;
            return 0;
        }
        res_5--;
    }

    return 0;
}
