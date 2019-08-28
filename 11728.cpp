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

int a[1000001], b[1000001], rs[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m, idx=0; cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    int i=0, j=0, k=0;
    while(i<n && j<m) {
        if(a[i] < b[j]) rs[k++] = a[i++];
        else rs[k++] = b[j++];
    }
    while(i<n) rs[k++] = a[i++];
    while(j<m) rs[k++] = b[j++];
    for(int i=0; i<n+m; i++) pt1(rs[i]);

    return 0;
}