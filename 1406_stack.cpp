#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    string s; cin >> s;
    stack<char> st, sub_s;
    vector<char> v;
    int cmd_cnt; cin >> cmd_cnt;
    for(int i=0; i<s.length(); i++) st.push(s[i]);
    while(cmd_cnt--) {
        char cmd; cin >> cmd;
        if(cmd == 'L') {
            if(!st.empty()) {
                sub_s.push(st.top());
                st.pop();
            } else continue;
        } else if(cmd == 'D') {
            if(!sub_s.empty()) {
                st.push(sub_s.top());
                sub_s.pop();
            } else continue;
        } else if(cmd == 'B') {
            if(!st.empty()) st.pop();
            else continue;
        } else {
            char val; cin >> val;
            st.push(val);
        }
    }
    while(!sub_s.empty()) {st.push(sub_s.top()); sub_s.pop();}
    while(!st.empty()) {
        v.push_back(st.top());
        st.pop();
    } reverse(v.begin(), v.end());
    for(char i : v) printf("%c", i);

    return 0;
}