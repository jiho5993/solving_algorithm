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

int a[500001];
int b[500001];
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n1, n2; cin >> n1 >> n2;
    fr(i, 0, n1) cin >> a[i];
    fr(i, 0, n2) cin >> b[i];
    sort(b, b+n2);
    fr(i, 0, n1) {
        int n = binary_search(b, b+n2, a[i]);
        if(!n) v.pb(a[i]);
    }
    pt(v.size());
    sort(all(v));
    for(int i : v) pt1(i);

    return 0;
}