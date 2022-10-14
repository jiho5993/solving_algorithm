#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int y = matrix.size();
    if(y == 0) return 0;
    int x = matrix[0].size();
    if(x == 0) return 0;
    vector<vector<int> > dp(y+1, vector<int>(x+1, 0));
    int ret=0;
    for(int i=1; i<=y; i++) {
      for(int j=1; j<=x; j++) {
        if(matrix[i-1][j-1] == '1') {
          dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
          ret = max(ret, dp[i][j]);
        }
      }
    }
    return ret*ret;
  }
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                 {'1', '0', '1', '1', '1'},
                                 {'1', '1', '1', '1', '1'},
                                 {'1', '0', '0', '1', '0'}};
  Solution s;
  cout << s.maximalSquare(matrix);

  return 0;
}