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
    
    int query, arr[201]; cin >> query;
    while(query--) {
        int n, idx=1; cin >> n;
        for(int i=0; i<n; i++) cin >> arr[i];
        while((abs(arr[idx-1]-arr[idx]) == 1 || abs(arr[idx-1]-arr[idx]) == n-1) && idx != n) idx++;
        idx != n ? pt("NO") : pt("YES");
    }

    return 0;
}