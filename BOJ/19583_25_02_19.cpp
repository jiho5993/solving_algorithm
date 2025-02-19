#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> nl;

int parser(string s) {
    string tmp = "";
    tmp += s[0];
    tmp += s[1];
    tmp += s[3];
    tmp += s[4];
    return stoi(tmp);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string S, E, Q; cin >> S >> E >> Q;
    int s = parser(S), e = parser(E), q = parser(Q);
    
    string T, N;
    int res = 0;
    while (cin >> T >> N) {
        int t = parser(T);
        if (t <= s) {
            nl[N] = true;
        } else if (e <= t && t <= q) {
            if (nl[N]) {
                res++;
                nl.erase(N);
            }
        }
    }
    cout << res;

    return 0;
}
