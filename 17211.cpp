#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 2e9;
const int MOD = 1000000007;

double dp[105][2];
double arr[4];

int main() {
    int n, tmp; scanf("%d %d", &n, &tmp);
    fr(i, 0, 4) scanf("%lf", &arr[i]);
    dp[1][0] = tmp ? arr[2] : arr[0];
    dp[1][1] = tmp ? arr[3] : arr[1];
    fr(i, 2, n+1) {
        dp[i][0] = dp[i-1][0]*arr[0]+dp[i-1][1]*arr[2];
        dp[i][1] = dp[i-1][0]*arr[1]+dp[i-1][1]*arr[3];
    }
    cout << round(dp[n][0]*1000) << " " << round(dp[n][1]*1000);

    return 0;
}