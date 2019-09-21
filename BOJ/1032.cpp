#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    string s, rs; cin >> s;
    rs = s;
    fr(i, 1, n) {
        cin >> s;
        fr(j, 0, s.size())
            if(s[j] != rs[j])
                rs[j] = '?';
    }
    cout << rs;

    return 0;
}