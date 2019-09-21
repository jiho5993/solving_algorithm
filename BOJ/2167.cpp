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

const int INF = 2147483648;
const int MOD = 1000000007;

int arr[301][301];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m; cin >> n >> m;
    fr(i, 0, n) {
        fr(j, 0, m)
            cin >> arr[i][j];
    }
    int t, x, y, z, w; cin >> t;
    while(t--) {
        cin >> x >> y >> z >> w;
        int s=0;
        fr(i, x-1, z) {
            fr(j, y-1, w)
                s += arr[i][j];
        }
        pt(s);
    }

    return 0;
}