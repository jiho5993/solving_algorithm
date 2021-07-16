#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
    cout << c*e+d << '\n';
    c == 0 ? cout << "0 0" : cout << a << ' ' << b*abs(c);

    return 0;
}