#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

class Solution {
public:
  bool checkValidString(string s) {
    int lo=0, hi=0;
    for(auto i:s) {
      lo += (i == '(' ? 1 : -1);
      hi += (i != ')' ? 1 : -1);
      if(hi < 0) break;
      lo = max(lo, 0);
    }
    return lo == 0;
  }
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  Solution s;
  cout << s.checkValidString("(***))");
  
  return 0;
}