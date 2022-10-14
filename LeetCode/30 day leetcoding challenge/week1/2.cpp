#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

class Solution {
public:
  bool isHappy(int n) {
    map<int, bool> m;
    m[n] = 1;
    bool flag = false;
    while(1) {
      int sum=0;
      while(n) {
        sum += (n%10)*(n%10);
        n /= 10;
      }
      n = sum;
      if(n == 1) {
        flag = true;
        break;
      }
      if(m[n]) break;
      m[n] = 1;
    }
    return flag;
  }
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  Solution s;
  cout << s.isHappy(2);
  
  return 0;
}