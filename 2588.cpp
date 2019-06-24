#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int a, b, rs; cin >> a >> b;
    rs = a*b;
    while(b) {
        printf("%d\n", (b%10)*a);
        b /= 10;
    }
    printf("%d\n", rs);

    return 0;
}