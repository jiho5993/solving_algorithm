#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

class Solution {
public:
  string foo(string tmp) {
    string s="";
    for(auto i:tmp) {
      s += i;
      for(int cnt=0; i=='#' && !s.empty() && cnt<2; cnt++) {
        s.pop_back();
        if(s.empty()) break;
      }
    }
    return s;
  }

  bool backspaceCompare(string S, string T) {
    string s, t;
    s = foo(S);
    t = foo(T);
    return s == t;
  }
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  Solution s;
  cout << s.backspaceCompare("a#c", "b");
  
  return 0;
}