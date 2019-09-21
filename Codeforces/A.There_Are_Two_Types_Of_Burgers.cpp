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
        int b, p, f, h, c, cnt_h=0, cnt_c=0;
        cin >> b >> p >> f >> h >> c;
        if(h < c) {
            while(f-- && b > 1) cnt_c++, b-=2;
            while(p-- && b > 1) cnt_h++, b-=2;
            pt(cnt_c*c + cnt_h*h);
        } else {
            while(p-- && b > 1) cnt_h++, b-=2;
            while(f-- && b > 1) cnt_c++, b-=2;
            pt(cnt_c*c + cnt_h*h);
        }
    }

    return 0;
}