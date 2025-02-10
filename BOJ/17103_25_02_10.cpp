#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000

bool arr[MAX+1];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;

    arr[1] = true;
    for (int i=2; i*i<=MAX; i++) {
        if (arr[i]) continue;
        for (int j=i*i; j<=MAX; j+=i) arr[j] = true;
    }

    while (T--) {
        int N; cin >> N;

        int res = 0;
        for (int i=2; i*2<=N; i++) {
            if (arr[i]) continue;
            if (arr[N-i]) continue;

            res++;
        }

        cout << res << '\n';
    }

    return 0;
}
