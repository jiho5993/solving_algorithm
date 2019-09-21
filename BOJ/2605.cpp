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
    
    int a; cin >> a;
    list<int> li;
    for(int i=1; i<=a; i++) {
        int q; cin >> q;
        auto iter = li.begin();
        for(; iter != li.end(); iter++, q--)
            if (q == 0) break;
        li.insert(iter, i);
    }
    for(auto it=li.rbegin(); it!=li.rend(); it++) pt1(*it);

    return 0;
}