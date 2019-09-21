#include <bits/stdc++.h>
using namespace std;

int n, arr[100001], cnt;
stack<int> st;
string s = "";

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=1; i<=n; i++) {
        st.push(i);
        s += "+";
        while(!st.empty()) {
            if(arr[cnt] != st.top()) break;
            else {
                s += "-";
                st.pop();
                cnt++;
            }
        }
    }
    if(st.empty()) {
        for(int i=0; i<s.length(); i++)
            cout << s[i] << '\n';
    } else cout << "NO" <<'\n';

    return 0;
}