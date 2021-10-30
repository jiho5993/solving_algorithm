#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

uint64_t mod_pow(uint64_t a, uint64_t b, uint64_t m) {
    uint64_t r = 1;

    a %= m;
    while (b > 0)  {
        if (b & 1) r = (r * a) % m;
        b >>= 1;
        a = (a * a) % m;
    }

    return r;
}

int miller_rabin(uint64_t S) {
    uint64_t k=0, q=S-1;

    while (!(q & 1)) {
        q >>= 1;
        k++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (a >= S-1) break;

        uint64_t x = mod_pow(a, q, S);
        bool flag = 0;

        if (x == 1 || x == S-1) continue;

        for (int j=1; j<k; j++) {
            x = mod_pow(x, 2, S);
            if (x == S-1) {
                flag = 1;
                break;
            }
        }

        if (!flag) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N, res=0; cin >> N;

    while (N--) {
        uint64_t S; cin >> S;

        if (!miller_rabin(2*S + 1)) continue;
        res++;
    }
    cout << res;

    return 0;
}