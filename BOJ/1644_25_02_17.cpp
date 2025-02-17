#include <bits/stdc++.h>
using namespace std;

#define MAX 4000000

bool arr[MAX+1];
int prime[MAX+1];

void eratos() {
    arr[1] = true;
    for (int i=2; i*i<=MAX; i++) {
        if (arr[i]) continue;
        for (int j=i*i; j<=MAX; j+=i) arr[j] = true;
    }

    int idx = 0;
    for (int i=2; i<=MAX+1; i++) {
        if (!arr[i]) {
            prime[idx++] = i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    eratos();

    int N; cin >> N;

    int s = 2, i1 = 0, i2 = 0;
    int res = 0;
    while (i2 <= N) {
        if (s == N) {
            res++;
            s -= prime[i1++];
        } else if (s > N) {
            s -= prime[i1++];
        } else {
            s += prime[++i2];
        }
    }

    cout << res << '\n';


    return 0;
}
