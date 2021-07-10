#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    long long M, s=0, x=0; cin >> M;
    while(M--) {
        int a, b; cin >> a;
        switch(a) {
            case 1:
                cin >> b;
                s += b;
                x ^= b;
                break;
            case 2:
                cin >> b;
                s -= b;
                x ^= b;
                break;
            case 3:
                cout << s << '\n';
                break;
            case 4:
                cout << x << '\n';
                break;
        }
    }

    return 0;
}