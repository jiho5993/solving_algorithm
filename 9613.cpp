#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define fr(i, a, b) for(int i=a; i<b; i++)
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
        int n, arr[101], rs=0; cin >> n;
        fr(i, 0, n) cin >> arr[i];
        fr(i, 0, n)
            fr(j, i+1, n)
                rs += __gcd(arr[i], arr[j]);
        pt(rs);
    }

    return 0;
}