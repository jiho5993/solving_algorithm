#include <bits/stdc++.h>
using namespace std;

int arr[100001];

bool bs(int t, int N) {
    int st = 0, en = N-1;
    while (st <= en) {
        int mid = (st+en)/2;
        if (arr[mid] == t) {
            return true;
        } else if (arr[mid] > t) {
            en = mid - 1;
        } else {
            st = mid + 1;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];

    sort(arr, arr+N);

    int M; cin >> M;
    while (M--) {
        int t; cin >> t;
        bs(t, N) ? cout << 1 << '\n' : cout << 0 << '\n';
    }

    return 0;
}
