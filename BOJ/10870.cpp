#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, arr[21] = {0, 1, 1};
    cin >> n;
    fr(i, 2, n+1) arr[i] = arr[i-2]+arr[i-1];
    cout << arr[n];

    return 0;
}