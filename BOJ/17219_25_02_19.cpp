#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, M; cin >> N >> M;
    for (int i=0; i<N; i++) {
        string a, b; cin >> a >> b;
        m[a] = b;
    }
    while (M--) {
        string s; cin >> s;
        cout << m[s] << '\n';
    }
    
    return 0;
}
