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
const int MOD = 10007;

int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, k; cin >> n >> k;
    dp[1][0] = 1;
    dp[1][1] = 1;
    fr(i, 2, n+1) {
        fr(j, 0, i+1) {
            if(i == j || j == 0) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j]+dp[i-1][j-1])%MOD;
        }
    }
    pt(dp[n][k]);

    return 0;
}