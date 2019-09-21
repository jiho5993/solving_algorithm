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
    
    int t, a[3] = {676, 26, 1}; cin >> t;
    while(t--) {
        string s, ss=""; cin >> s;
        int frs=0;
        for(int i=0; i<8; i++) {
            if(i < 3) frs += (s[i]-'A')*a[i];
            else if(i > 3) ss += s[i];
        }
        pt(abs(frs-stoi(ss)) <= 100 ? "nice" : "not nice");
    }

    return 0;
}