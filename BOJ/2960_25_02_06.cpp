#include <bits/stdc++.h>
using namespace std;

bool arr[1001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, K; cin >> N >> K;
    arr[1] = true;

    for (int i=2; i<=N; i++) {
        if (arr[i]) continue;
        for (int j=i; j<=N; j+=i) {
            if (arr[j]) continue;
            arr[j] = true;
            K--;
            if (K == 0) {
                cout << j;
                return 0;
            }
        }
    }

    return 0;
}
