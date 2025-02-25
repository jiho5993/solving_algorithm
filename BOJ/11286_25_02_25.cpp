#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

priority_queue<pii, vector<pii>, greater<pii> > pq;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    while (N--) {
        int a; cin >> a;
        if (a == 0) {
            if (pq.empty()) cout << "0\n";
            else {
                cout << pq.top().second << '\n';
                pq.pop();
            }
        } else {
            pq.push({ abs(a), a });
        }
    }

    return 0;
}
