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

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int dp[501][501];
int arr[501][501];
int n, rs=0;

int dfs(int x, int y) {
    if(dp[x][y]) return dp[x][y];
    dp[x][y] = 1;
    fr(i, 0, 4) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx >= n || xx < 0 | yy > n || yy >= n) continue;
        if(arr[xx][yy] > arr[x][y])
            dp[x][y] = max(dp[x][y], dfs(xx, yy)+1);
    }
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n;
    fr(i, 0, n)
        fr(j, 0, n)
            cin >> arr[i][j];
    fr(i, 0, n)
        fr(j, 0, n)
            rs = max(rs, dfs(i, j));
    pt(rs);

    return 0;
}