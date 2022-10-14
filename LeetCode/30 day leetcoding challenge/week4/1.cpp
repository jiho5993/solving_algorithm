#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    int ret=0, sz=nums.size();
    for(int i=0; i<sz; i++) {
      int s=0;
      for(int j=i; j<sz; j++) {
        s += nums[j];
        if(s == k) ret++;
      }
    }
    return ret;
  }
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  Solution s;
  vector<int> nums = {1, 1, 1};
  cout << s.subarraySum(nums, 2);
  
  return 0;
}