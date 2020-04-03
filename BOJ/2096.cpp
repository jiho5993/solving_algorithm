#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int arr[100005][5];
int dp[2][3][4];

void swap() {
  for(int i=1; i<=3; i++) {
    swap(dp[0][1][i], dp[0][2][i]);
    swap(dp[1][1][i], dp[1][2][i]);
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N; cin >> N;
  for(int i=1; i<=N; i++)
    for(int j=1; j<=3; j++)
      cin >> arr[i][j];
  for(int i=1; i<=3; i++) dp[0][1][i] = dp[1][1][i] = arr[1][i];
  for(int i=2; i<=N; i++) {
    for(int j=1; j<=3; j++) {
      if(j == 1) {
        dp[0][2][j] = max(dp[0][1][1], dp[0][1][2])+arr[i][j];
        dp[1][2][j] = min(dp[1][1][1], dp[1][1][2])+arr[i][j];
      }
      else if(j == 2) {
        dp[0][2][j] = max(dp[0][1][1], max(dp[0][1][2], dp[0][1][3]))+arr[i][j];
        dp[1][2][j] = min(dp[1][1][1], min(dp[1][1][2], dp[1][1][3]))+arr[i][j];
      }
      else {
        dp[0][2][j] = max(dp[0][1][2], dp[0][1][3])+arr[i][j];
        dp[1][2][j] = min(dp[1][1][2], dp[1][1][3])+arr[i][j];
      }
    }
    swap();
  }
  cout << *max_element(dp[0][1]+1, dp[0][1]+4) << ' ' << *min_element(dp[1][1]+1, dp[1][1]+4);
  
  return 0;
}