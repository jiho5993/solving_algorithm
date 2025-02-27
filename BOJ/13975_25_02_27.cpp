#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        priority_queue<ll, vector<ll>, greater<ll> > pq;
        int N; cin >> N;
        for (int i=0; i<N; i++) {
            int a; cin >> a;
            pq.push(a);
        }

        ll res = 0;
        while (pq.size() > 1) {
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();

            res += (a+b);
            pq.push(a+b);
        }

        cout << res << '\n';
    }

    return 0;
}
