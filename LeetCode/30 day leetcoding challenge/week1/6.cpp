#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

class Solution {
public:
  vector<vector<string> > groupAnagrams(vector<string>& strs) {
    vector<vector<string> > ret;
    ret.resize(strs.size());
    sort(all(strs));
    unordered_map<string, vector<string> > m;
    for(auto i:strs) {
      string s = i;
      sort(all(s));
      m[s].push_back(i);
    }
    int idx=0;
    for(auto i=m.begin(); i!=m.end(); i++) {
      for(auto j:i->second) ret[idx].push_back(j);
      idx++;
    }
    ret.resize(idx);
    return ret;
  }
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  Solution s;
  vector<string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};
  for(auto i:s.groupAnagrams(v)) {
    for(auto j:i) cout << j << ' ';
    cout << '\n';
  }
  
  return 0;
}