#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    long long N, res=1; cin >> N;
    for(int i=1; i<=N; i++) {
        res = (res*i)%100000000000000;
        while(res%10 == 0) res /= 10;
    }
    cout << res%10;

    return 0;
}