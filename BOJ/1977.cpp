#include <bits/stdc++.h>
using namespace std;

int min(int a, int b) { return a < b ? a : b; }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int m, n, minn=10000, sum=0; cin >> m >> n;
    bool chk = false;
    for(int i=1; i*i<=n; i++) {
        if(i*i>=m) {
            minn = min(i*i, minn);
            sum += i*i;
            chk = true;
        }
    }
    if(!chk) printf("-1");
    else printf("%d\n%d\n", sum, minn);

    return 0;
}