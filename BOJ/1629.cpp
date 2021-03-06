#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define len(a) ((int)(a.length()))
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 2147483648;
const int MOD = 1000000007;

ll pow(ll a, ll b, ll c) {
    if(b == 0) return 1;
    else {
        ll rs = pow(a, b/2, c);
        rs = rs*rs%c;
        if(b%2 == 1) return rs*a%c;
        else return rs;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll a, b, c;
    cin >> a >> b >> c;
    pt(pow(a, b, c));

    return 0;
}