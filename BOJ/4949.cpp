#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  string s;
  while(1) {
    getline(cin, s);
    if(s == ".") break;
    stack<char> st;
    bool flag = true;
    for(auto i:s) {
      if(i == '[' || i == '(') st.push(i);
      else if(i == ']') {
        if(!st.empty() && st.top() == '[') st.pop();
        else {
          flag = 0;
          break;
        }
      }
      else if(i == ')') {
        if(!st.empty() && st.top() == '(') st.pop();
        else {
          flag = 0;
          break;
        }
      }
    }
    flag && st.empty() ? cout << "yes\n" : cout << "no\n";
  }

  return 0;
}