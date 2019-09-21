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

const int dx[2] = {1, 0};
const int dy[2] = {0, 1};
ll dp[101][101];
ll arr[101][101], visit[101][101];
ll n;

ll dfs(int x, int y) {
    if(x == n-1 && y == n-1) return 1;
    if(arr[x][y] == 0 || visit[x][y] || dp[x][y]) return dp[x][y];
    if(x >= n || y >= n) return 0;
    visit[x][y] = 1;
    fr(i, 0, 2) {
        int xx = x + dx[i]*arr[x][y];
        int yy = y + dy[i]*arr[x][y];
        dp[x][y] += dfs(xx, yy);
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
    pt(dfs(0, 0));

    return 0;
}