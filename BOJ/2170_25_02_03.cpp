#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

pii arr[1000001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    for (int i=0; i<N; i++) {
        int a, b; cin >> a >> b;
        arr[i] = {a, b};
    }

    sort(arr, arr+N);

    ll res = 0;
    int m = -1e9;
    for (int i=0; i<N; i++) {
        int a, b;
        tie(a, b) = arr[i];

        if (m <= a) {
            res += (b - a);
            m = b;
        }
        else if (m < b) {
            res += (b - m);
            m = b;
        } else continue;
    }

    cout << res;

    return 0;
}
