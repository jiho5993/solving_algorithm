#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

class Solution {
public:
  int _y, _x;
  int minPathSum(vector<vector<int>>& grid) {
    _y = grid.size();
    _x = grid[0].size();
    for(int i=0; i<_y; i++) {
      for(int j=0; j<_x; j++) {
        if(i == 0 && j == 0) continue;
        if(i == 0) {
          grid[i][j] += grid[i][j-1];
          continue;
        }
        else if(j == 0) {
          grid[i][j] += grid[i-1][j];
          continue;
        }
        else grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
      }
    }
    return grid[_y-1][_x-1];
  }
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  vector<vector<int> > grid = {{1, 3, 1},
                               {1, 5, 1},
                               {4, 2, 1}};
  Solution s;
  cout << s.minPathSum(grid);
  
  return 0;
}