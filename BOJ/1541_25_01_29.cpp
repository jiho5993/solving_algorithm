#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;

    int res = 0;
    string cur = "";
    bool flag = false;
    for (int i=0; i<s.size() + 1; i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '\0') {
            if (flag) res -= stoi(cur);
            else res += stoi(cur);
            cur = "";

            if (s[i] == '-') flag = true;
        } else {
            cur += s[i];
        }
    }

    cout << res;

    return 0;
}
