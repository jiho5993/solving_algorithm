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

const int INF = 2147483648;
const int MOD = 1000000007;

int dp[10005][3];
int arr[1002][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin >> n;
    fr(i, 0, n) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    fr(i, 0, 3) dp[0][i] = arr[0][i];
    fr(i, 1, n+1) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
        dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + arr[i][2];
    }
    pt(min(min(dp[n][0], dp[n][1]), dp[n][2]));

    return 0;
}