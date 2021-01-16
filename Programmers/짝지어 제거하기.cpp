#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    stack<char> st;
    for(auto i:s) {
        if(st.empty()) st.push(i);
        else {
            if(st.top() == i) st.pop();
            else st.push(i);
        }
    }

    return st.empty();
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    auto res = solution("baabaa");
    cout << res;

    return 0;
}