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
    
    int e, s, m, cnt=0; cin >> e >> s >> m;
    while(1) {
        e--, s--, m--, cnt++;
        if(e+s+m == 0) break;
        if(!e) e = 15;
        if(!s) s = 28;
        if(!m) m = 19;
    }
    pt(cnt);

    return 0;
}