#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    stack<char> st;
    string s; cin >> s;
    int cnt=0, n=1;
    bool chk = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '(') {
            n *= 2;
            st.push(s[i]);
        } else if(s[i] == '[') {
            n *= 3;
            st.push(s[i]);
        } else if(s[i] == ')') {
            if(st.empty() || st.top() != '(') {
                chk = 1;
                break;
            } else if(s[i-1] == '(') cnt += n;
            st.pop();
            n /= 2;
        } else {
            if(st.empty() || st.top() != '[') {
                chk = 1;
                break;
            } else if(s[i-1] == '[') cnt += n;
            st.pop();
            n /= 3;
        }
    }
    if(chk || !st.empty()) cout << '0';
    else cout << cnt;

    return 0;
}