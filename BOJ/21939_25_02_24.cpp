#include <bits/stdc++.h>
using namespace std;

int arr[100001];
set<int> p[101];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    while (N--) {
        int P, L; cin >> P >> L;
        p[L].insert(P);
        arr[P] = L;
    }
    int M; cin >> M;
    while (M--) {
        string cmd; cin >> cmd;
        if (cmd == "add") {
            int P, L; cin >> P >> L;
            p[L].insert(P);
            arr[P] = L;
        } else if (cmd == "solved") {
            int P; cin >> P;
            p[arr[P]].erase(P);
        } else {
            int x; cin >> x;
            if (x == 1) {
                for (int i=100; i>=1; i--) {
                    if (p[i].size() > 0) {
                        cout << *(--p[i].end()) << '\n';
                        break;
                    }
                }
            } else {
                for (int i=1; i<=100; i++) {
                    if (p[i].size() > 0) {
                        cout << *p[i].begin() << '\n';
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
