#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()

int N, ret=1;
int arr[100001];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    int p = arr[N-1];
    for(int i=N-2; i>=0; i--) {
        if(p < arr[i]) {
            p = max(p, arr[i]);
            ret++;
        }
    }
    cout << ret;

    return 0;
}