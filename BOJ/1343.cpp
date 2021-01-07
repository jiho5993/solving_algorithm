#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    string s, res=""; cin >> s;
    for(int i=0; i<s.length(); ) {
        if(s[i] == '.') {
            res += '.';
            i++;
            continue;
        }
        int cnt=0;
        for(int j=i; j<s.length() && s[j] == 'X'; j++, cnt++);
        i += cnt;
        if(cnt&1) {
            cout << -1;
            return 0;
        }
        while(cnt) {
            if(cnt >= 4) {
                res += "AAAA";
                cnt -= 4;
            } else {
                res += "BB";
                cnt -= 2;
            }
        }
    }
    cout << res;

    return 0;
}