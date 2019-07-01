#include <bits/stdc++.h>
using namespace std;

int n, arr[101], sum, cnt=1;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<n-1; i++) {
        if(arr[i]) sum += cnt;
        if(arr[i+1] && arr[i]) cnt++;
        else cnt = 1;
    }
    if(arr[n-1]) sum += cnt;
    printf("%d\n", sum);

    return 0;
}
