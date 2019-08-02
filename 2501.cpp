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
    
    int n, k; cin >> n >> k;
    vector<int> v;
    for(int i=1; i*i<= n; i++)
        if(n%i == 0) {
            v.pb(i);
            if(n/i == i) continue;
            v.pb(n/i);
        }
    sort(all(v));
    if(v.size() >= k) pt(v[k-1]);
    else pt('0');

    return 0;
}