#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int res = 0;

    int N; cin >> N;
    for (int i=0; i<N; i++) {
        int a; cin >> a;
        pq.push(a);
    }

    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + b);
        res += (a + b);
    }

    cout << res << '\n';

    return 0;
}
