#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, pi[1001]; cin >> n;
    for(int i=0; i<n; i++) cin >> pi[i];
    sort(pi, pi+n);
    int rs=0, cnt=0;
    for(int i=0; i<n; i++) {
        cnt += pi[i];
        rs += cnt;
    }
    printf("%d\n", rs);

    return 0;
}