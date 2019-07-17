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

const int INF = 2147483648-1;
const int MOD = 1000000007;

int n, o;
int arr[11];
int op[4];
bool visit[11];
int mx = -INF, mn = INF;

void dfs(int pl, int mi, int mu, int di, int ss, int tot) {
    if(ss == n) {
        mx = max(mx, tot);
        mn = min(mn, tot);
        return;
    }
    if(pl > 0) dfs(pl-1, mi, mu, di, ss+1, tot+arr[ss]);
    if(mi > 0) dfs(pl, mi-1, mu, di, ss+1, tot-arr[ss]);
    if(mu > 0) dfs(pl, mi, mu-1, di, ss+1, tot*arr[ss]);
    if(di > 0) dfs(pl, mi, mu, di-1, ss+1, tot/arr[ss]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n;
    fr(i, 0, n) cin >> arr[i];
    fr(i, 0, 4) cin >> op[i];
    dfs(op[0], op[1], op[2], op[3], 1, arr[0]);
    pt(mx);
    pt(mn);

    return 0;
}