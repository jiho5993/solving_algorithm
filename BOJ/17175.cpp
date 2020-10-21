#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N, a=1, b=1; cin >> N;
    for(int i=2; i<=N; i++) {
        int tmp = a;
        a = b;
        b =(tmp+b+1)%MOD;
    }
    cout << b;

    return 0;
}