#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, m, k, cnt=0; cin >> n >> m >> k;
    while(k != 0) {
        if(m*2 < n) {
            n--;
            k--;
        } else {
            m--;
            k--;
        }
    }
    while(n >= 2 && m >= 1) {
        cnt++;
        n-=2;
        m--;
    }
    printf("%d\n", cnt);

    return 0;
}