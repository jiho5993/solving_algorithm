#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000;
int arr[1000005]={1,};

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    for(int i=1; i<=1000000; i++)
        arr[i] = (arr[(int)floor(i-sqrt(i))]+arr[(int)floor(log(i))]+arr[(int)floor(i*sin(i)*sin(i))])%MOD;
    while(1) {
        int N; cin >> N;
        if(N == -1) break;
        cout << arr[N] << '\n';
    }

    return 0;
}