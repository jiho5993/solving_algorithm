#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

bool arr[MAX+1];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    arr[1] = true;
    for (int i=2; i*i<=MAX; i++) {
        if (arr[i]) continue;
        for (int j=i*i; j<=MAX; j+=i) arr[j] = true;
    }

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        for (int i=N/2; i>=2; i--) {
            if (arr[i]) continue;
            if (arr[N-i]) continue;
            cout << i << ' ' << N-i << '\n';
            break;
        }
    }

    return 0;
}
