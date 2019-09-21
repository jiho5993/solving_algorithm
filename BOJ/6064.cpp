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
    
    int t, m, n, x, y; cin >> t;
    while(t--) {
        cin >> m >> n >> x >> y;
        x--, y--;
        bool flag = false;
        fr(i, 0, n) {
            int val = m*i+x;
            if(val%n == y) {
                flag = true;
                pt(val+1);
                break;
            }
        }
        if(!flag) pt("-1");
    }

    return 0;
}