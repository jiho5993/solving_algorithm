#include <bits/stdc++.h>
using namespace std;

int arr[100001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, M; cin >> N >> M;
    for (int i=0; i<N; i++) cin >> arr[i];

    int i1 = 0, i2 = 0;
    int res = 1e6;

    int s = arr[i1];
    while (i1 < N && i2 < N) {
        if (s >= M) {
            res = min(i2 - i1 + 1, res);
            s -= arr[i1++];
        } else {
            s += arr[++i2];
        }
    }

    res == 1e6 ? cout << 0 : cout << res;

    return 0;
}
