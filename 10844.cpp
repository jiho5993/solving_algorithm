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
const int MOD = 1000000007-7;

int dp[101][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    ll n, rs=0; cin >> n;
    fr(i, 1, 10) dp[1][i] = 1;
    fr(i, 2, n+1) {
        fr(j, 0, 10) {
            if(j == 0) dp[i][j] = dp[i-1][1];
            else if(j == 9) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = dp[i-1][j-1]+dp[i-1][j+1];
            dp[i][j] %= MOD;
        }
    }
    fr(i, 0, 10) rs += dp[n][i];
    pt(rs%MOD);

    return 0;
}