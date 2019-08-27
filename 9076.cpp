#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 1e9;
const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int arr[5];
        for(int i=0; i<5; i++) cin >> arr[i];
        sort(arr, arr+5);
        arr[3]-arr[1]>=4 ? pt("KIN") : pt(arr[1]+arr[2]+arr[3]);
    }

    return 0;
}