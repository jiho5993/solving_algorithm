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

int dp[31][31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t; cin >> t;
    for(int i=0; i<31; i++) {
        dp[i][i] = dp[i][0] = 1;
        for(int j=1; j<i; j++)
            dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
    }
    while(t--) {
        int a, b; cin >> a >> b;
        pt(dp[b][a]);
    }

    return 0;
}