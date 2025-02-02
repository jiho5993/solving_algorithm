#include <bits/stdc++.h>
using namespace std;

#define ll long long

int arr[1000001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        for (int i=0; i<N; i++) cin >> arr[i];

        ll res = 0;
        int h = arr[N-1];
        for (int i=N-2; i>=0; i--) {
            if (h >= arr[i]) res += (h - arr[i]);
            else h = arr[i];
        }

        cout << res << '\n';
    }

    return 0;
}
