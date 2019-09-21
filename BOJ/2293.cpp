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
int arr[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, k; cin >> n >> k;
    fr(i, 0, n) cin >> arr[i];
    dp[0] = 1;
    fr(i, 0, n) {
        fr(j, 1, k+1) {
            if(j >= arr[i])
                dp[j] += dp[j-arr[i]];
        }
    }
    pt(dp[k]);

    return 0;
}