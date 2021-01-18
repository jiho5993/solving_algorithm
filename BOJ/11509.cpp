#include <bits/stdc++.h>
using namespace std;

int arr[1000001];

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    int N, res=0; cin >> N;
    for(int i=0; i<N; i++) {
        int a; cin >> a;
        if(arr[a+1]) arr[a+1]--;
        else res++;
        arr[a]++;
    }
    cout << res;

    return 0;
}