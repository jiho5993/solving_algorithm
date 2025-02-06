#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int X; cin >> X;

    int i = 0;
    while (X > i) {
        X -= i;
        i++;
    }

    int a = X, b = (i + 1) - X;
    if (i&1) swap(a, b);
    cout << a << '/' << b;

    return 0;
}
