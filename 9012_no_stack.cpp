#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int cnt=0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') cnt++;
            else {
                cnt--;
                if(cnt < 0) break;
            }
        }
        if(!cnt) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}