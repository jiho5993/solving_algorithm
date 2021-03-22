#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;

ll N, P, Q;
map<ll, ll> arr;

ll foo(ll i) {
    ll &ret = arr[i];
    if(ret) return ret;
    return arr[i] = foo(i/P) + foo(i/Q);
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N >> P >> Q;
    arr[0] = 1;
    cout << foo(N);

    return 0;
}