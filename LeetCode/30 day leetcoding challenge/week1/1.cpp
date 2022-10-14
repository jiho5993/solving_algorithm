#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

class solution {
public:
  int singleNumber(vector<int> &nums) {
    map<int, bool> m;
    for(auto i:nums) m[i] = !m[i];
    int ret=0;
    for(auto i:m) {
      if(i.second) {
        ret = i.first;
        break;
      }
    }
    return ret;
  }
};


int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  solution s;
  vector<int> v = {4,1,2,1,2};
  cout << s.singleNumber(v);
  
  return 0;
}