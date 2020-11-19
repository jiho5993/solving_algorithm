#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

double arr[100001];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);
    double res = arr[N-1];
    for(int i=0; i<N-1; i++) res += arr[i]/2;
    cout << res;

    return 0;
}