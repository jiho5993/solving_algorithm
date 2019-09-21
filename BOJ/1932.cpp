#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 1e9;
const int MOD = 1000000007;

int arr[501][501];
int dp[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, rs=0; cin >> n;
    fr(i, 1, n+1)
        fr(j, 1, i+1)
            cin >> arr[i][j];
    dp[1][1] = arr[1][1];
    fr(i, 1, n+1) {
        fr(j, 1, i+1) {
            if(j == 1) dp[i][j] = dp[i-1][j] + arr[i][j];
            else if(i == j) dp[i][j] = dp[i-1][j-1] + arr[i][j];
            else dp[i][j] = max(dp[i-1][j] ,dp[i-1][j-1]) + arr[i][j];
            if(rs < dp[i][j]) rs = dp[i][j];
        }
    }
    pt(rs);

    return 0;
}