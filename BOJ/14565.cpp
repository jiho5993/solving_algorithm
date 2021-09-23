#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int64_t mul_inv(int64_t a, int64_t m) {
    int64_t d0 = a, d1 = m;
    int64_t x0 = 1, x1 = 0;

    while (d1 > 1) {
        int64_t q = d0/d1;
        d0 = d0 - q*d1; swap(d0, d1);
        x0 = x0 - q*x1; swap(x0, x1);
    }

    if (d1 == 1) {
        return x1 > 0 ? x1 : x1 + m;
    } else {
        return -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int64_t N, A; cin >> N >> A;
    cout << N-A << ' ' << mul_inv(A, N);

    return 0;
}