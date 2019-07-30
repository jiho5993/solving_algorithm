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

ll arr[1001][1001];
ll dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m; cin >> n >> m;
    fr(i, 1, n+1) {
        fr(j, 1, m+1)
            cin >> arr[i][j];
    }
    fr(i, 1, n+1) {
        fr(j, 1, m+1) 
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + arr[i][j];
    }
    pt(dp[n][m]);

    return 0;
}