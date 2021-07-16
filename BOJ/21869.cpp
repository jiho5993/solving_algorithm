#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N; cin >> N;
    N >= 2 ? cout << 2*N-2 << '\n' : cout << 1 << '\n';
    for(int i=0; i<N; i++) cout << 1 << ' ' << i+1 << '\n';
    if(N > 2)
        for(int i=2; i<N; i++)
            cout << N << ' ' << i << '\n';

    return 0;
}