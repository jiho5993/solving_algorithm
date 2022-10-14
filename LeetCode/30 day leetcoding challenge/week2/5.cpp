#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

class Solution {
public:
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq;
    for(auto i:stones) pq.push(i);
    while(pq.size() != 1) {
      int a = pq.top(); pq.pop();
      int b = pq.top(); pq.pop();
      pq.push(a-b);
    }
    return pq.top();
  }
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  vector<int> v={2,7,4,1,8,1};
  Solution s;
  cout << s.lastStoneWeight(v);
  
  return 0;
}