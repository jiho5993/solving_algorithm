#include <bits/stdc++.h>
using namespace std;

int H, W, res=0;
int arr[501];

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> H >> W;
    for(int i=0; i<W; i++) cin >> arr[i];
    for(int i=1; i<W-1; i++) {
        int l=arr[i], r=arr[i];
        for(int j=0; j<i; j++) l = max(l, arr[j]);
        for(int j=W-1; j>i; j--) r = max(r, arr[j]);
        res += min(l, r)-arr[i];
    }
    cout << res;

    return 0;
}