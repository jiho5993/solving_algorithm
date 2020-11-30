#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

int N, S, M;
int arr[101];
int dp[101][1001];

int foo(int idx, int v) {
    if(v < 0 || v > M) return -2;
    if(idx == N) return v;

    int &ret = dp[idx][v];
    if(ret != -1) return ret;
    return ret = max(foo(idx+1, v+arr[idx]), foo(idx+1, v-arr[idx]));
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N >> S >> M;
    for(int i=0; i<N; i++) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    int res = foo(0, S);
    if(res == -2) cout << -1;
    else cout << res;

    return 0;
}