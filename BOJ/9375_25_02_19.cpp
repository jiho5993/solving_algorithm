#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        m.clear();
        int N; cin >> N;
        for (int i=0; i<N; i++) {
            string a, b; cin >> a >> b;
            m[b]++;
        }
        int res = 1;
        for (auto i: m) {
            res *= (i.second+1);
        }
        cout << res - 1 << '\n';
    }

    return 0;
}
