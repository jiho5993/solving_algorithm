#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

class Solution {
public:
  int search(vector<int>& nums, int target) {
    vector<pair<int, int> > v;
    for(int i=0; i<nums.size(); i++) v.pb({nums[i], i});
    sort(all(v));
    int lo=0, hi=v.size();
    int idx=-1;
    while(lo < hi) {
      int mid = (lo+hi)/2;
      if(v[mid].first == target) {
        idx = v[mid].second;
        break;
      }
      else if(v[mid].first < target) lo = mid+1;
      else hi = mid;
    }
    return idx;
  }
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  vector<int> v={1};
  Solution s;
  cout << s.search(v, 1);
  
  return 0;
}