#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, arr[51]; cin >> n;
    fr(i, 0, n) cin >> arr[i];
    sort(arr, arr+n);
    cout << arr[0]*arr[n-1];

    return 0;
}