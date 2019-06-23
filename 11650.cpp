#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, a, b; cin >> n;
    vector<pair<int, int> > vp;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        vp.push_back(make_pair(a, b));
    }
    sort(vp.begin(), vp.end());
    for(int i=0; i<n; i++) printf("%d %d\n", vp[i].first, vp[i].second);

    return 0;
}