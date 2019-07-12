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

int cnt;
vector<pii> vp;
void hanoi(int n, int from, int mid, int to) {
    cnt++;
    if(n == 1) vp.pb(mp(from, to));
    else {
        hanoi(n-1, from, to, mid);
        vp.pb(mp(from, to));
        hanoi(n-1, mid, from, to);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin >> n;
    hanoi(n, 1, 2, 3);
    pt(cnt);
    fr(i, 0, sz(vp)) cout << vp[i].first << " " << vp[i].second << '\n';

    return 0;
}