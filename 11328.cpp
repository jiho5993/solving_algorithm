#include <bits/stdc++.h>
#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define len(a) ((int)(a.length()))
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '
#define pt3(a, b, c) cout << (a) << ' ' << (b) << ' ' << (c) << ' '
#define pt4(a, b, c, d) cout << (a) << ' ' << (b) << ' ' << (c) << ' ' << (d) << ' '
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n; cin >> n;
    string s, ss;
    while(n--) {
        cin >> s >> ss;
        sort(all(s)); sort(all(ss));
        if(s == ss) pt("Possible");
        else pt("Impossible");
    }

    return 0;
}