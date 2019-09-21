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

int dp[100005];
int arr[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, q; cin >> n;
    fr(i, 1, n+1) cin >> arr[i];
    dp[1] = arr[1];
    q = arr[1];
    fr(i, 2, n+1) {
        if(dp[i-1]+arr[i] > arr[i])
            dp[i] = dp[i-1] + arr[i];
        else dp[i] = arr[i];
        q = max(q, dp[i]);
    }
    pt(q);

    return 0;
}