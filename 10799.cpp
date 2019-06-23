#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    string s; cin >> s;
    stack<int> st;
    int sum=0;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '(') st.push(s[i]);
        else {
            st.pop();
            if(s[i-1] == '(') sum += st.size();
            else sum++;
        }
    }
    printf("%d\n", sum);

    return 0;
}