#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, b; cin >> n >> m;
    for(int i=1; i*i<=m/n; i++) {
        if((m/n)%i == 0) {
            if(__gcd(i, (m/n)/i) == 1) {
                a = i;
                b = (m/n)/i;
            }
        }
    }
    cout << a*n << ' ' << b*n;

    return 0;
}