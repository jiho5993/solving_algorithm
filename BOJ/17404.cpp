#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1001][3];
int dp[1001][3];

int foo(int idx, int cur, int f) {
    int &ret = dp[idx][cur];
    if(ret != -1) return ret;
    ret = 1000001;

    if(idx == N-1) {
        for(int i=0; i<3; i++) {
            if(cur == i || f == i) continue;
            ret = min(ret, arr[idx][i]);
        }
    } else {
        for(int i=0; i<3; i++) {
            if(cur == i) continue;
            ret = min(ret, foo(idx+1, i, f) + arr[idx][i]);
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    int res=1000001;
    for(int i=0; i<3; i++) {
        memset(dp, -1, sizeof(dp));
        res = min(res, foo(1, i, i) + arr[0][i]);
    }
    cout << res;

    return 0;
}