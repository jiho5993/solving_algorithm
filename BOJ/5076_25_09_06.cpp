#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr
#define ll long long

pair<string, int> get_keyword(string s, int idx) {
    string res = "";
    bool flag = false;

    while (idx < s.size()) {
        if (s[idx] == '>') {
            if (s[idx-1] == '/') return {"", -1};
            else return {res, idx};
        }
        if (!flag) {
            if (s[idx] == ' ') flag = true;
            else res += s[idx];
        }
        idx++;
    }

    return {"", -1};
}

void solve() {
    while (1) {
        string s;
        getline(cin, s);
        if (s == "#") break;

        stack<string> pool;
        int idx = 0;
        while (idx < s.size()) {
            if (s[idx] == '<') {
                pair<string, int> k;
                if (idx+1 < s.size()) {
                    if (s[idx+1] == '/') k = get_keyword(s, idx+2);
                    else k = get_keyword(s, idx+1);
                }

                if (k.second == -1) {
                    idx++;
                    continue;
                } else {
                    idx = k.second;
                    if (!pool.empty() && pool.top() == k.first) pool.pop();
                    else pool.push(k.first);
                }
            } else {
                idx++;
            }
        }

        if (pool.empty()) cout << "legal\n";
        else cout << "illegal\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
