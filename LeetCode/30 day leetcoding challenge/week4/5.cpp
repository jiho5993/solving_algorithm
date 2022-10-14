#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    text1 = '0' + text1;
    text2 = '0' + text2;
    int sz1 = text1.size(), sz2 = text2.size();
    vector<vector<int> > lcs(sz1+1, vector<int>(sz2, 0));
    for(int i=1; i<sz1; i++) {
      for(int j=1; j<sz2; j++) {
        if(text1[i] == text2[j]) lcs[i][j] = lcs[i-1][j-1] + 1;
        else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
      }
    }
    return lcs[sz1-1][sz2-1];
  }
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  Solution s;
  cout << s.longestCommonSubsequence("abc", "cde");
  
  return 0;
}