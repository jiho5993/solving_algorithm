#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N; cin >> N;
    while(N--) {
        int a, b, c=1; cin >> a >> b;
        while(b--) c = (c*a)%10;
        if(c == 0) c = 10;
        cout << c << '\n';
    }

    return 0;
}