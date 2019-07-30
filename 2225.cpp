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
const int MOD = 1000000007-7;

ll dp[201][201];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, k; cin >> n >> k;
    fr(i, 0, n+1) dp[1][i] = 1;
    fr(i, 2, k+1) {
        fr(j, 0, n+1) {
            fr(l, 0, j+1)
                dp[i][j] += dp[i-1][l];
            dp[i][j] %= MOD;
        }
    }
    pt(dp[k][n]);

    return 0;
}