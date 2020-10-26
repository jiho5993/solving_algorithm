#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define MAX 1e7

int S;
int dp[1001][1001];

int foo(int tmp, int cb) {
    if(tmp > 1000 || tmp < 1 || cb > S) return MAX;
    if(tmp == S) return 0;

    int &ret = dp[tmp][cb];
    if(ret != -1) return ret;
    ret = MAX;

    ret = min(ret, foo(tmp, tmp)+1); // copy
    ret = min(ret, foo(tmp+cb, cb)+1); // paste
    ret = min(ret, foo(tmp-1, cb)+1); // delete
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> S;
    memset(dp, -1, sizeof(dp));
    cout << foo(1, 0);

    return 0;
}