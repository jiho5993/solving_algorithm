#include <bits/stdc++.h>
using namespace std;

int N, ret;
int arr[9];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);
    do {
        int tmp = 0;
        for(int i=0; i<N-1; i++)
            tmp += abs(arr[i]-arr[i+1]);
        ret = max(ret, tmp);
    } while(next_permutation(arr, arr+N));
    cout << ret;

    return 0;
}