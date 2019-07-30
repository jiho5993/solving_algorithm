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

int dp[20][20];
int n, m, k;
int cnt = 0, pos_x, pos_y;

void foo() {
    fr(i, 2, pos_y+1)
        fr(j, 2, pos_x+1)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
    fr(i, pos_x+1, m+1) dp[pos_y][i] = dp[pos_y][i-1];
    fr(i, pos_y+1, n+1) dp[i][pos_x] = dp[i-1][pos_x];
    fr(i, pos_y+1, n+1)
        fr(j, pos_x+1, m+1)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> m >> k;
    if(k) {
        fr(i, 0, n) {
            fr(j, 0, m) {
                cnt++;
                if (cnt == k) {
                    pos_y = i+1;
                    pos_x = j+1;
                }
            }
        }
    }
    fr(i, 1, m+1) dp[1][i] = 1;
    fr(i, 1, n+1) dp[i][1] = 1;
    if(k) foo();
    else {
        fr(i, 2, n+1)
            fr(j, 2, m+1)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
    }
    pt(dp[n][m]);

    return 0;
}