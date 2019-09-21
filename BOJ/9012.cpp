#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    string s;
    while(t--) {
        cin >> s;
        stack<char> st;
        bool chk= 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == ')') {
                if(st.empty()) {
                    cout << "NO" << '\n';
                    chk=1;
                    break;
                }
                else st.pop();
            } else st.push(s[i]);
        }
        if(!chk) {
            if(st.empty()) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }

    return 0;
}