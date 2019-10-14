#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n; cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) cout << '*';
        cout << '\n';
    }
    for(int i=n-1; i>0; i--) {
        for(int j=n-1; j>=n-i; j--) cout << '*';
        cout << '\n';
    }

    return 0;
}