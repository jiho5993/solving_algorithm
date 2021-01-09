#include <bits/stdc++.h>
using namespace std;

int N;
int L[21], J[21];
int dp[21][101];

int foo(int a, int b) {
    int &ret = dp[a][b];
    if(ret != -1) return ret;
    if(a >= N) return 0;
    ret = 0;

    if(b-L[a] > 0) ret = max(foo(a+1, b-L[a])+J[a], foo(a+1, b));
    else ret = max(ret, foo(a+1, b));

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> L[i];
    for(int i=0; i<N; i++) cin >> J[i];

    memset(dp, -1, sizeof(dp));
    cout << foo(0, 100);

    return 0;
}