#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int N, M;
int arr[100001];

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> arr[i];
    for(int i=1; i<N; i++) arr[i] += arr[i-1];
    while(M--) {
        int a, b; cin >> a >> b;
        cout << arr[b-1]-arr[a-2] << '\n';
    }

    return 0;
}