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
    
    int t, cnt=0; cin >> t;
    bool chk[26];
    while(t--) {
        bool flag = false;
        fill(chk, chk+26, false);
        string s; cin >> s;
        for(int i=0; i<s.size(); i++) {
            if(chk[s[i]-'a']) {
                if(s[i-1] != s[i]) {
                    flag = true;
                    break;
                }
            }
            chk[s[i]-'a'] = true;
        }
        if(!flag) cnt++;
    }
    pt(cnt);

    return 0;
}