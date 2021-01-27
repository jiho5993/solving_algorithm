#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int N, H;
int u[100001], d[100001];

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N >> H;
    N >>= 1;
    for(int i=0; i<N; i++) cin >> d[i] >> u[i];
    int res=200001, cnt=1;
    sort(d, d+N);
    sort(u, u+N);
    for(int i=1; i<=H; i++) {
        int tmp = N - (lower_bound(d, d+N, i)-d);
        tmp += N - (upper_bound(u, u+N, H-i)-u);
        if(res == tmp) cnt++;
        else if(res > tmp) {
            res = tmp;
            cnt = 1;
        }
    }
    cout << res << ' ' << cnt;

    return 0;
}