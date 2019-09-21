#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

set<string> ss;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s;
    int n, cnt=0; cin >> n >> s;
    ss.insert(s);
    fr(i, 1, n) {
        cin >> s;
        bool flag = false;
        for(auto it=ss.begin(); it!=ss.end() && !flag; it++) {
            string tmp = *it;
            fr(j, 0, s.size()) {
                if(tmp == s) {
                    flag = true;
                    break;
                } else tmp+=tmp[0], tmp.erase(0, 1);
            }
        }
        if(flag) continue;
        ss.insert(s);
    }
    cout << ss.size();

    return 0;
}