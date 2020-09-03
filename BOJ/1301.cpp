#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
int N, arr[6];
ll dp[11][11][11][11][11][7][7];

ll foo(int a, int b, int c, int d, int e, char p, char pp) {
    if(a == 0 && b == 0 && c == 0 && d == 0 && e == 0)
        return 1;

    ll &ret = dp[a][b][c][d][e][p][pp];
    if(ret != -1) return ret;
    ret = 0;

    if(p != 'a' && pp != 'a' && a > 0)
        ret += foo(a-1, b, c, d, e, 'a', p);
    if(p != 'b' && pp != 'b' && b > 0)
        ret += foo(a, b-1, c, d, e, 'b', p);
    if(p != 'c' && pp != 'c' && c > 0)
        ret += foo(a, b, c-1, d, e, 'c', p);
    if(p != 'd' && pp != 'd' && d > 0)
        ret += foo(a, b, c, d-1, e, 'd', p);
    if(p != 'e' && pp != 'e' && e > 0)
        ret += foo(a, b, c, d, e-1, 'e', p);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    cout << foo(arr[0], arr[1], arr[2], arr[3], arr[4], 'n', 'n');

    return 0;
}