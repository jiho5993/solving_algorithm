#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, rs = 0;
    cin >> n;
    while (n != 0) {
        if (n % 2) rs++;
        n /= 2;
    }
    cout << rs;

    return 0;
}
