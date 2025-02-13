#include <bits/stdc++.h>
using namespace std;

int arr[500001];

int lower_idx(int t, int N) {
	int st = 0, en = N;
	while (st < en) {
		int mid = (st+en)/2;
		if (arr[mid] >= t) en = mid;
		else st = mid + 1;
	}
	return st;
}

int upper_idx(int t, int N) {
    int st = 0, en = N;
    while (st < en) {
        int mid = (st+en)/2;
        if (arr[mid] > t) en = mid;
        else st = mid + 1;
    }
    return st;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];

    sort(arr, arr+N);

    int M; cin >> M;
    while (M--) {
        int t; cin >> t;
        cout << upper_idx(t, N) - lower_idx(t, N) << ' ';
    }

    return 0;
}
