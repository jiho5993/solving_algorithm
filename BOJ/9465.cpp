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

int arr[2][100001];
int dp[2][100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t, n; cin >> t;
    while(t--) {
        cin >> n;
        fr(i, 0, 2) {
            fr(j, 1, n+1)
                cin >> arr[i][j];
        }
        dp[0][1] = arr[0][1];
        dp[1][1] = arr[1][1];
        fr(i, 2, n+1) {
            dp[0][i] = max(dp[1][i-1], dp[1][i-2])+arr[0][i];
            dp[1][i] = max(dp[0][i-1], dp[0][i-2])+arr[1][i];
        }
        pt(max(dp[0][n], dp[1][n]));
    }

    return 0;
}