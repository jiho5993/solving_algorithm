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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double dis = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
        if(x1 == x2 && y1 == y2) {
            if(r1 == r2) pt(-1);
            else pt(0);
        } else if(r1+r2 > dis && dis > abs(r1-r2)) pt(2);
        else if(abs(r1-r2) == dis || r1+r2 == dis) pt(1);
        else pt(0);
    }

    return 0;
}