#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

class Solution {
public:
  int _y, _x;
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  int numIslands(vector<vector<char>>& grid) {
    _y = grid.size();
    if(_y == 0) return 0;
    _x = grid[0].size();
    if(_x == 0) return 0;
    int ret=0;
    for(int i=0; i<_y; i++) {
      for(int j=0; j<_x; j++) {
        if(grid[i][j] == '1') {
          ret++;
          queue<pair<int, int> > qp;
          qp.push({i, j});
          while(!qp.empty()) {
            int x = qp.front().second;
            int y = qp.front().first;
            qp.pop();
            for(int k=0; k<4; k++) {
              int xx = x + dx[k];
              int yy = y + dy[k];
              if((0 <= xx && xx < _x) && (0 <= yy && yy < _y) && grid[yy][xx] == '1') {
                qp.push({yy, xx});
                grid[yy][xx] = '0';
              }
            }
          }
          grid[i][j] = '0';
        }
      }
    }
    return ret;
  }
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  Solution s;
  vector<vector<char> > grid = {{'1','1','0','0','0'},
                                {'1','1','0','0','0'},
                                {'0','0','1','0','0'},
                                {'0','0','0','1','1'}};
  cout << s.numIslands(grid);
  
  return 0;
}