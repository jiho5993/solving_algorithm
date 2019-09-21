#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 1e9;
const int MOD = 1000000007;

int arr[501][2];
int dp[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i][0] >> arr[i][1];
    // for(int i=1; i<n; i++) dp[1][i] = arr[i-1][0]*arr[i-1][1]*arr[i][1];
    for(int i=1; i<n; i++) {
        for(int j=1; j<=n-i; j++) {
            int minNum = INT32_MAX;
            int r = i+j;
            for(int k=j; k<r; k++) minNum = min(minNum, dp[j][k]+dp[k+1][r]+arr[j][0]*arr[k][1]*arr[r][1]);
            dp[j][r] = minNum;
        }
    }

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) pt1(dp[i][j]);
        cout << '\n';
    }
    pt(dp[1][n]);

    return 0;
}