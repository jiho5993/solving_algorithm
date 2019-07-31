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

bool cmp(pii a, pii b) {
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    vector<pii> vp;
    int cnt=0;
    int n; cin >> n;
    fr(i, 0, n) {
        int a, b; cin >> a >> b;
        vp.pb({a, b});
    }
    sort(all(vp), cmp);
    int tmp = vp[0].first;
    fr(i, 0, n) {
        if(tmp <= vp[i].first) {
            tmp = vp[i].second;
            cnt++;
        }
    }
    pt(cnt);

    return 0;
}