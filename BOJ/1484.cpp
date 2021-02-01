#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    int G; cin >> G;
    int l=1, r=1;
    bool flag = false;
    while(l <= 1e5 && r <= 1e5) {
        int cur = l*l-r*r;
        if(cur == G) {
            cout << l << '\n';
            flag = true;
        }
        if(cur > G) r++;
        else l++;
    }
    if(!flag) cout << -1;

    return 0;
}