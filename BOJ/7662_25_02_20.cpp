#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        multiset<int> s;

        while (N--) {
            char cmd;
            int a;
            cin >> cmd >> a;
    
            if (cmd == 'I') {
                s.insert(a);
            } else {
                if (s.empty()) continue;
                if (a == 1) s.erase(--s.end());
                else s.erase(s.begin());
            }
        }

        if (s.empty()) cout << "EMPTY\n";
        else cout << *(--s.end()) << ' ' << *s.begin() << '\n';

    }

    return 0;
}
