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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin >> n;
    int y=0, m=0;
    fr(i, 0, n) {
        int a; cin >> a;
        y += (a/30)+1;
        m += (a/60)+1;
    }
    int q=y*10, w=m*15;
    if(q < w) pt2('Y', q);
    else if(q == w) {pt2('Y', 'M'); pt1(q);}
    else pt2('M', w);

    return 0;
}