#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int N, M, K;
int arr[4000001];
bool flag[4000001];

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N >> M >> K;
    for(int i=0; i<M; i++) cin >> arr[i];
    sort(arr, arr+M);
    for(int i=0; i<K; i++) {
        int a; cin >> a;
        int idx = upper_bound(arr, arr+M, a)-arr;
        while(flag[idx]) idx++;
        flag[idx] = true;
        cout << arr[idx] << '\n';
    }

    return 0;
}