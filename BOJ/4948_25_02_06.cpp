#include <bits/stdc++.h>
using namespace std;

bool arr[300001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    arr[1] = true;
    for (int i=2; i*i<=300000; i++) {
        if (arr[i]) continue;
        for (int j=i*i; j<=300000; j+=i) arr[j] = true;
    }

    while (1) {
        int N; cin >> N;
        if (N == 0) {
            break;
        }

        int res = 0;
        for (int i=N+1; i<=N*2; i++) res += !arr[i];
        cout << res << '\n';
    }

    return 0;
}
