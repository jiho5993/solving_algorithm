#include <bits/stdc++.h>
using namespace std;

#define ll long long

priority_queue<ll, vector<ll>, greater<ll> > gpq;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, M; cin >> N >> M;
    for (int i=0; i<N; i++) {
        int a; cin >> a;
        gpq.push(a);
    }

    while (M--) {
        ll a = gpq.top();
        gpq.pop();
        ll b = gpq.top();
        gpq.pop();

        gpq.push(a + b);
        gpq.push(a + b);
    }

    ll res = 0;
    while (!gpq.empty()) {
        res += gpq.top();
        gpq.pop();
    }

    cout << res;

    return 0;
}
