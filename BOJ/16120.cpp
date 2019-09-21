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

const int INF = 1e9;
const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    string s, ss=""; cin >> s;
    fr(i, 0, s.size()) {
        ss += s[i];
        if(ss.size() >= 4) {
            string tmp="";
            fr(i, ss.size()-4, ss.size()) tmp += ss[i];
            if(tmp == "PPAP") {
                fr(i, 0, 4) ss.pop_back();
                ss += 'P';
            }
        }
    }
    if(ss == "P") pt("PPAP");
    else pt("NP");

    return 0;
}