#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
int N, i1, i2;
ll arr[100001], res=2e9+1;

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);
    int i=0, j=N-1;
    while(i < j) {
        ll s = arr[i]+arr[j];
        if(llabs(s) < res) {
            res = llabs(s);
            i1 = i;
            i2 = j;
        }
        if(s < 0) i++;
        else j--;
    }
    cout << arr[i1] << ' ' << arr[i2];

    return 0;
}