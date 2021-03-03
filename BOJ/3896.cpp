#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MAX = 1299709;
bool arr[MAX+1];

void eratos() {
    for(int i=2; i<=MAX/2; i++) {
        if(arr[i]) continue;
        for(int j=i*2; j<=MAX; j+=i) arr[j] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    eratos();
    int T; cin >> T;
    while(T--) {
        int a; cin >> a;
        int l=a, r=a;
        while(arr[l]) l--;
        while(arr[r]) r++;
        cout << r-l << '\n';
    }

    return 0;
}