#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;

string A, B, C;
ll dp[21][101][2];

ll foo(int a, int b, int c) {
    if(a == A.size()) return 1;

    ll &ret = dp[a][b][c];
    if(ret != -1) return ret;
    ret = 0;

    if(c == 0) { // B
        for(int i=b; i<B.size(); i++)
            if(B[i] == A[a])
                ret += foo(a+1, i+1, 1);
    } else { // C
        for(int i=b; i<C.size(); i++)
            if(C[i] == A[a])
                ret += foo(a+1, i+1, 0);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> A >> B >> C;
    memset(dp, -1, sizeof(dp));
    cout << foo(0, 0, 0) + foo(0, 0, 1);

    return 0;
}