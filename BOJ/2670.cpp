#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int N;
double arr[10001], res;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
        res = max(res, arr[i]);
    }

    for(int i=1; i<N; i++) {
        arr[i] = max(arr[i], arr[i]*arr[i-1]);
        res = max(res, arr[i]);
    }
    cout << fixed;
    cout.precision(3);
    cout << res;

    return 0;
}