#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int sz = nums.size();
    vector<int> a(sz, 1), b(sz, 1);
    for(int i=1; i<sz; i++) a[i] = nums[i-1]*a[i-1];
    for(int i=sz-2; i>=0; i--) b[i] = nums[i+1]*b[i+1];
    vector<int> ret(sz);
    for(int i=0; i<sz; i++) ret[i] = a[i]*b[i];
    return ret;
  }
};


int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  Solution s;
  vector<int> v = {1,2,3,4};
  vector<int> ans = s.productExceptSelf(v);
  for(auto i:ans) cout << i << ' ';
  
  return 0;
}