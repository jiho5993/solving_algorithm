#include <bits/stdc++.h>
#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define len(a) ((int)(a.length()))
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n; cin >> n;
    string s;
    while(n--) {
        stack<char> st, stt;
        vector<char> v;
        cin >> s;
        fr(i, 0, len(s)) {
            if(s[i] == '<') {
                if(!st.empty()) {
                    stt.push(st.top());
                    st.pop();
                } else continue;
            } else if(s[i] == '>') {
                if(!stt.empty()) {
                    st.push(stt.top());
                    stt.pop();
                } else continue;
            } else if(s[i] == '-') {
                if(!st.empty()) st.pop();
                else continue;
            } else st.push(s[i]);
        }
        while(!stt.empty()) {st.push(stt.top()); stt.pop();}
        while(!st.empty()) {v.push_back(st.top()); st.pop();} reverse(v.begin(), v.end());
        for(char i : v) printf("%c", i); printf("\n");
    }

    return 0;
}