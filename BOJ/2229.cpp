#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int N;
int arr[1001];
int dp[1001];

int foo(int idx) {
    if(idx == N) return 0;
    int &res = dp[idx];
    if(res != -1) return res;

    res = 0;
    int l = 987654321, h = -1;
    for(int i=idx; i<N; i++) {
        l = min(l, arr[i]);
        h = max(h, arr[i]);
        res = max(res, h-l+foo(i+1));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    cout << foo(0);

    return 0;
}