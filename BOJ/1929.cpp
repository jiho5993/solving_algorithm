#include <bits/stdc++.h>
using namespace std;

bool arr[1000001];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    arr[1] = true;
    for(int i=2; i*i<=1000000; i++) {
        if(!arr[i]) {
            for(int j=i+i; j<=1000000; j+=i)
                arr[j] = true;
        }
    }
    for(int i=n; i<=m; i++) {
        if(!arr[i])
            printf("%d\n", i);
    }

    return 0;
}