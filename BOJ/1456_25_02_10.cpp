#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool arr[10000001];

void eratos() {
    arr[1] = true;
    for (int i=2; i*i<=10000000; i++) {
        if (arr[i]) continue;
        for (int j=i*i; j<=10000000; j+=i) arr[j] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll A, B; cin >> A >> B;

    eratos();

    ll res = 0;
    for (ll i=2; i*i<=B; i++) {
        if (arr[i]) continue;
        ll tmp = i;
        while (1) {
            if (tmp > B/i) {
                break;
            }
            tmp *= i;
            if (tmp >= A) {
                res++;
            }
        }
    }

    cout << res;

    return 0;
}
