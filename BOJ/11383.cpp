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
    
    int a, b; cin >> a >> b;
    string ss[11];
    for(int i=0; i<a; i++) {
        string s; cin >> s;
        for(int j=0; j<b; j++)
            for(int k=0; k<2; k++)
                ss[i] += s[j];
    }
    bool flag = false;
    for(int i=0; i<a; i++) {
        string s; cin >> s;
        if(ss[i] != s) {flag = 1; break;}
    }
    pt(flag ? "Not Eyfa" : "Eyfa");

    return 0;
}