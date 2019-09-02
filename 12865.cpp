#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int dp[100001];
int w[101], v[101];
int n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> k;
    fr(i, 0, n) cin >> w[i] >> v[i];
    fr(i, 0, n) {
        for(int j=k; j>=1; j--) {
            if(w[i] <= j)
                dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }
    cout << dp[k];

    return 0;
}