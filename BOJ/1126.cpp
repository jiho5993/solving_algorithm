#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define INF 2e9
int N;
int arr[51];
int dp[51][250001];

int foo(int cnt, int diff) {
    if(diff > 250000) return -INF;
    if(cnt == N) {
        if(diff == 0) return 0;
        else return -INF;
    }

    int &ret = dp[cnt][diff];
    if(ret != -1) return ret;
    ret = -INF;

    ret = max(ret, foo(cnt+1, diff));
    ret = max(ret, foo(cnt+1, diff+arr[cnt]));
    if(arr[cnt] > diff) ret = max(ret, diff+foo(cnt+1, arr[cnt]-diff));
    else ret = max(ret, arr[cnt]+foo(cnt+1, diff-arr[cnt]));

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    int ret = foo(0, 0);
    ret ? cout << ret : cout << -1;

    return 0;
}