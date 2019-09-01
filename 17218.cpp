#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vii;
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

int lcs[50][50];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    string a, b, rs=""; cin >> a >> b;
    a = '0'+a, b = '0'+b;
    int sa = a.size(), sb = b.size();
    fr(i, 1, sb) {
        fr(j, 1, sa) {
            if(b[i] == a[j]) lcs[i][j] = lcs[i-1][j-1]+1;
            else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
    sa--, sb--;
    while(sa > 0 && sb > 0) {
        if(lcs[sb][sa] == lcs[sb][sa-1]) sa--;
        else if(lcs[sb][sa] == lcs[sb-1][sa]) sb--;
        else if(lcs[sb][sa]-1 == lcs[sb-1][sa-1]) {
            rs += a[sa];
            sa--, sb--;
        }
    }
    reverse(all(rs));
    pt(rs);

    return 0;
}