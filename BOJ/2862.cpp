#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;

ll dp[101] = {1, 1};

ll foo(ll n) {
    for(int i=0; i<101; i++) {
        if(dp[i] == n) return n;
        if(dp[i+1] > n) return foo(n-dp[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=2; i<101; i++) dp[i] = dp[i-1] + dp[i-2];
    ll N; cin >> N;
    cout << foo(N);

    return 0;
}