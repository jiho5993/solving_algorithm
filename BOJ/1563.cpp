#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ll long long
#define V(T) vector<T>
#define VP(T) vector<pair<T, T> >
#define P(T) pair<T, T>
#define PQ(T) priority_queue<T>

const int MOD = 1e6;
int N;
int dp[1001][2][3];

int foo(int d, int l, int a) {
    if(l == 2 || a == 3) return 0;
    if(d > N) return 1;
    int &ret = dp[d][l][a];
    if(ret != -1) return ret;
    ret = (foo(d+1, l, 0) + foo(d+1, l+1, 0) + foo(d+1, l, a+1))%MOD;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N;
    memset(dp, -1, sizeof(dp));
    cout << foo(1, 0, 0);

    return 0;
}