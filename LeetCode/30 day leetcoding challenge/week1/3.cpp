#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int sz = nums.size(), ret=0;
    vector<int> dp(sz+1, 0);
    ret = dp[0] = nums[0];
    for(int i=1; i<sz; i++) {
      if(dp[i-1]+nums[i] > nums[i]) dp[i] = dp[i-1] + nums[i];
      else dp[i] = nums[i];
      ret = max(dp[i], ret);
    }
    return ret;
  }
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  Solution s;
  vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
  cout << s.maxSubArray(v);
  
  return 0;
}