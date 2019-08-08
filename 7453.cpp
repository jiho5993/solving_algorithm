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

#define MAX 4001

ll abcd[4][MAX];
ll ab[MAX*MAX];
ll cd[MAX*MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    ll n, cnt=0, idx=0; cin >> n;
    fr(i, 0, n)
        cin >> abcd[0][i] >> abcd[1][i] >> abcd[2][i] >> abcd[3][i];
    fr(i, 0, n) {
        fr(j, 0, n) {
            ab[idx] = abcd[0][i]+abcd[1][j];
            cd[idx++] = abcd[2][i]+abcd[3][j];
        }
    }
    sort(cd, cd+idx);
    fr(i, 0, idx) {
        auto u = upper_bound(cd, cd+idx, -ab[i]);
        auto l = lower_bound(cd, cd+idx, -ab[i]);
        cnt += u-l;
    }
    pt(cnt);

    return 0;
}