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

int dp[100001];
int arr[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin >> n;
    fr(i, 1, n+1) cin >> arr[i];
    dp[1] = arr[1];
    dp[2] = dp[1]+arr[2];
    fr(i, 3, n+1) dp[i] = max(max(dp[i-3]+arr[i-1]+arr[i], dp[i-1]), dp[i-2]+arr[i]);
    pt(dp[n]);

    return 0;
}