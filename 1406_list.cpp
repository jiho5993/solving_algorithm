#include <bits/stdc++.h>
#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define len(a) ((int)(a.length()))
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '
#define pt3(a, b, c) cout << (a) << ' ' << (b) << ' ' << (c) << ' '
#define pt4(a, b, c, d) cout << (a) << ' ' << (b) << ' ' << (c) << ' ' << (d) << ' '
using namespace std;

string s;
char cmd, val;
int cmd_cnt;
list<char> ls;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> s;
    cin >> cmd_cnt;
    fr(i, 0, len(s)) ls.pb(s[i]);

    auto cur = ls.end();
    while(cmd_cnt--) {
        cin >> cmd;
        if(cmd == 'L') {if(cur != ls.begin()) cur--;}
        else if(cmd == 'D') {if(cur != ls.end()) cur++;}
        else if(cmd == 'B') {
            if(cur != ls.begin()) {
                auto tmp = cur;
                cur--;
                ls.erase(cur);
                cur = tmp;
            }
        }
        else if(cmd == 'P') {
            cin >> val;
            ls.insert(cur, val);
        }
    }
    for(auto i: ls) cout << i;

    return 0;
}