#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int T; cin >> T;
    while(T--) {
        int N, mx=0; cin >> N;
        int *arr = new int[N+1];
        for(int i=0; i<N; i++) cin >> arr[i];
        sort(arr, arr+N);
        for(int i=2; i<N; i++) mx = max(mx, arr[i]-arr[i-2]);
        cout << mx << '\n';
    }

    return 0;
}