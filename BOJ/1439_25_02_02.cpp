#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;

    int g0 = 0, g1 = 0;
    char prev = s[0];
    for (int i=1; i<s.size()+1; i++) {
        char tmp = s[i];
        if (prev == tmp) continue;
        else {
            if (prev == '0') g0++;
            else g1++;
            prev = tmp;
        }
    }

    cout << min(g0, g1);

    return 0;
}
