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
    
    ll n, q; cin >> n >> q;
    ll m = n*n / 2;
    if(n%2) m++;
    while(q--) {
        ll a, b, num; cin >> a >> b;
        num = (a-1)*n + (b-1);
        bool chk = false;
        if((a+b)%2) chk = true;
        if(chk) pt(m + num/2 + 1);
        else pt(num/2 + 1);
    }

    return 0;
}