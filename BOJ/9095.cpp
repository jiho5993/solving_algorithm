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

int dp[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t, n; cin >> t;
    dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 4, dp[4] = 7;
    while(t--) {
        cin >> n;
        fr(i, 5, n+1) dp[i] = dp[i-3]+dp[i-2]+dp[i-1];
        pt(dp[n]);
    }

    return 0;
}