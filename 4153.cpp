#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int a, b, c;
    while(1) {
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) break;
        int arr[3] = {a, b, c};
        sort(arr, arr+3);
        if(arr[2]*arr[2] == arr[1]*arr[1] + arr[0]*arr[0])
            printf("right\n");
        else printf("wrong\n");
    }

    return 0;
}