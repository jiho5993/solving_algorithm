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

int n;
vector<pair<int, string> > vp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n;
    fr(i, 0, n) {
        string s; cin >> s;
        vp.pb({s.length(), s});
    }
    sort(all(vp));
    vp.erase(unique(all(vp)), vp.end());
    fr(i, 0, vp.size()) pt(vp[i].second);

    return 0;
}