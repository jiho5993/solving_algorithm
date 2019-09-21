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

vector<pii> vp;
int dp[20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin >> n;
    fr(i, 0, n) {
        int a, b; cin >> a >> b;
        vp.pb({a, b});
    }
    fr(i, 0, n) {
        if(dp[i] > dp[i+1]) dp[i+1] = dp[i];
        if(dp[i+vp[i].first] < dp[i]+vp[i].second)
            dp[i+vp[i].first] = dp[i]+vp[i].second;
    }
    pt(dp[n]);

    return 0;
}