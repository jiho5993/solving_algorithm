#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll arr[100001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, M; cin >> N >> M;
    for (int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);

    int i1 = 0, i2 = 0;
    ll res = 2e9+1;

    while (i1 < N && i2 < N) {
        ll tmp = arr[i2] - arr[i1];
        if (tmp >= M) {
            res = min(tmp, res);
            i1++;
        } else {
            i2++;
        }
    }

    cout << res;

    return 0;
}
