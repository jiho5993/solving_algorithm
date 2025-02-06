#include <bits/stdc++.h>
using namespace std;

int arr[101];

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        for (int i=0; i<N; i++) cin >> arr[i];

        long long res = 0;
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) res += gcd(arr[i], arr[j]);
        }
        cout << res << '\n';
    }

    return 0;
}
