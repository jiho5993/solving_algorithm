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
const int MOD = 9901;

int n, m, rs=0;
int arr[1001][1001];
int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> m;
    fr(i, 1, n+1) {
        string s; cin >> s;
        fr(j, 1, m+1)
            arr[i][j] = s[j-1]-'0';
    }
    fr(i, 1, n+1) {
        fr(j, 1, m+1) {
            if(arr[i][j]) {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                rs = max(rs, dp[i][j]);
            }
        }
    }
    pt(rs*rs);

    return 0;
}