#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int ret=0;
    for(int i=1; i<prices.size(); i++) {
      if(prices[i] > prices[i-1])
        ret += (prices[i]-prices[i-1]);
    }
    return ret;
  }
};
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  Solution s;
  vector<int> v = {1, 2, 3, 4, 5};
  cout << s.maxProfit(v);
  
  return 0;
}