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

ll arr[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, cnt=1, maxNum=1; cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    ll rs = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i-1] == arr[i]) cnt++;
        else cnt=1;
        if(maxNum < cnt) {
            maxNum = cnt;
            rs = arr[i];
        }
    }
    pt(rs);

    return 0;
}