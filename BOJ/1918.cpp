#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

string s, rs="";
stack<char> sc;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s;
    fr(i, 0, s.size()) {
        if('A' <= s[i] && s[i] <= 'Z') rs += s[i];
        else {
            switch (s[i])
            {
            case '(':
                sc.push(s[i]);
                break;
            case '*':
            case '/':
                while(!sc.empty() && (sc.top() == '*' || sc.top() == '/')) {
                    rs += sc.top();
                    sc.pop();
                }
                sc.push(s[i]);
                break;
            case '+':
            case '-':
                while(!sc.empty() && sc.top() != '(') {
                    rs += sc.top();
                    sc.pop();
                }
                sc.push(s[i]);
                break;
            case ')':
                while(!sc.empty() && sc.top() != '(') {
                    rs += sc.top();
                    sc.pop();
                }
                sc.pop();
                break;
            }
        }
    }
    while(!sc.empty()) {
        rs += sc.top();
        sc.pop();
    }
    cout << rs;

    return 0;
}