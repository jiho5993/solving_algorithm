#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    int X;
    while(cin >> X) {
        int N, arr[1000001]; cin >> N;
        X *= 1e7;
        for(int i=0; i<N; i++) cin >> arr[i];
        sort(arr, arr+N);
        int l=0, r=N-1;
        bool flag = false;
        while(l < r) {
            int s = arr[l]+arr[r];
            if(s == X) {
                flag = true;
                break;
            }
            if(s < X) l++;
            else r--;
        }
        if(flag) cout << "yes " << arr[l] << ' ' << arr[r] << '\n';
        else cout << "danger\n";
    }

    return 0;
}