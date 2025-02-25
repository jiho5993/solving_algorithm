#include <bits/stdc++.h>
using namespace std;

bool arr[500005];
set<int> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, Q; cin >> N >> Q;
    for (int i=1; i<=N; i++) {
        cin >> arr[i];
        if (arr[i]) {
            s.insert(i);
        }
    }

    int p = 1;
    while (Q--) {
        int q; cin >> q;
        if (q == 1) {
            int i; cin >> i;
            arr[i] = !arr[i];
            if (arr[i]) {
                s.insert(i);
            } else {
                s.erase(i);
            }
        } else if (q == 2) {
            int x; cin >> x;
            p += (x%N);
            if (p > N) p %= N;
        } else {
            if (s.empty()) cout << "-1\n";
            else {
                if (arr[p]) {
                    cout << "0\n";
                    continue;
                }

                auto it = s.upper_bound(p);
                if (it == s.end()) cout << (N-p) + *s.upper_bound(0) << '\n';
                else cout << *it - p << '\n';
            }
        }
    }

    return 0;
}
