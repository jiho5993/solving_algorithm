#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    ll a, b; cin >> a >> b;
    ll res = gcd(a, b);
    while(res--) cout << 1;

    return 0;
}