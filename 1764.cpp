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

int n, m;
set<string> ss;
vector<string> vs;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    fr(i, 0, n) {
        string s; cin >> s;
        ss.insert(s);
    }
    while(m--) {
        string s; cin >> s;
        if(ss.find(s) == ss.end()) continue;
        else vs.pb(s);
    }
    pt(vs.size());
    sort(all(vs));
    for(auto i : vs) pt(i);

    return 0;
}