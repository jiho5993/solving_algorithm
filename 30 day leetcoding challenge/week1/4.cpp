#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    vector<int> v(nums.size(), 0);
    int idx=0;
    for(auto i:nums) {
      if(i != 0)
        v[idx++] = i;
    }
    nums = v;
  }
};


int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  Solution s;
  vector<int> v = {0,1,0,3,12};
  s.moveZeroes(v);
  for(auto i:v) cout << i << ' ';
  
  return 0;
}