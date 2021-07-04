#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int T; cin >> T;
    while(T--) {
        int a, b; cin >> a >> b;
        cout << lcm(a, b) << '\n';
    }

    return 0;
}