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
    cin.ignore();
    while(t--) {
        string s; getline(cin, s);
        vector<char> v;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' ') {
                reverse(all(v));
                for(auto i : v) cout << i;
                cout << ' ';
                v.clear();
                continue;
            }
            v.pb(s[i]);
        }
        reverse(all(v));
        for(auto i : v) cout << i;
        cout << '\n';
    }

    return 0;
}