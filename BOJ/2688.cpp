#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int T; cin >> T;
    while(T--) {
        ll n, s=0; cin >> n;
        ll dp[65][10]={0,};
        for(int i=0; i<10; i++) dp[1][i] = 1;
        for(int i=2; i<=n; i++) {
            for(int j=0; j<10; j++) {
                for(int k=0; k<=j; k++) {
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
        for(int i=0; i<10; i++) s += dp[n][i];
        cout << s << '\n';
    }

    return 0;
}