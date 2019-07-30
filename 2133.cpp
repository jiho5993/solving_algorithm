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

int dp[100005]={1, 0, 3};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin >> n;
    if(n%2) {
        pt("0");
        return 0;
    }
    for(int i=4; i<=n; i+=2) {
        dp[i] += 3*dp[i-2];
        for(int j=4; j<=i; j+=2)
            dp[i] += 2*dp[i-j];
    }
    pt(dp[n]);
    fr(i, 0, n+1) pt1(dp[i]);
}