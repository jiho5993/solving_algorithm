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
const int MOD = 15746;

int dp[201];
int arr[201];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin >> n;
    fr(i, 1, n+1) cin >> arr[i];
    fr(i, 1, n+1) {
        int m=0;
        fr(j, 0, i)
            if(arr[i] > arr[j] && m < dp[j])
                m = dp[j];
        dp[i] = m+1;
    }
    pt(n-*max_element(dp, dp+n+1));

    return 0;
}