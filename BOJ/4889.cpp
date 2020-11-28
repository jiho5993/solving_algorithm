#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    string s;
    int T = 1;
    while(cin >> s) {
        if(s[0] == '-') break;
        stack<char> st;
        for(auto i:s) {
            if(i == '{') st.push(i);
            else {
                if(!st.empty() && st.top() == '{') {
                    st.pop();
                    continue;
                }
                st.push(i);
            }
        }
        int res=0;
        while(!st.empty()) {
            char c1 = st.top();
            st.pop();
            char c2 = st.top();
            st.pop();
            if(c1 == c2) res++;
            else res += 2;
        }
        cout << T++ << ". " << res << '\n';
    }

    return 0;
}