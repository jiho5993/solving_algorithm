#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define fr(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 2147483648;
const int MOD = 1000000007;

int n;
vector<pii> vp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    fr(i, 0, n) {
        int x, y; cin >> x >> y;
        vp.pb({y, x});
    }
    sort(all(vp));
    fr(i, 0, vp.size()) {
        pt2(vp[i].second, vp[i].first);
        cout << '\n';
    }

    return 0;
}