#include <bits/stdc++.h>
using namespace std;

string res[100001];
unordered_map<string, bool> m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    while (N--) {
        string s, c; cin >> s >> c;
        if (c == "enter") {
            m[s] = true;
        } else {
            m[s] = false;
        }
    }

    int idx = 0;
    for (auto i: m) {
        if (i.second) {
            res[idx++] = i.first;
        }
    }
    sort(res, res+idx, greater<string>());
    for (int i=0; i<idx; i++) cout << res[i] << '\n';

    return 0;
}
