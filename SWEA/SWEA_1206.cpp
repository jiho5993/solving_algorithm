#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int tc = 1; tc <= 10; tc++) {
        int rs = 0, n, arr[1001];
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 2; i < n - 2; i++) {
            if(arr[i] > arr[i-2] && arr[i] > arr[i-1])
                if(arr[i] > arr[i+2] && arr[i] > arr[i+1])
                    rs += arr[i]-max(arr[i-1], max(arr[i-2], max(arr[i+1], arr[i+2])));
        }
        cout << "#" << tc << ' ' << rs << '\n';
    }

    return 0;
}