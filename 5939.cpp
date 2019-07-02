#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, h, m, s; cin >> n;
    vector<pair<int, pair<int, int> > > vp;
    while(n--) {
        cin >> h >> m >> s;
        vp.push_back(make_pair(h, make_pair(m, s)));
    }
    sort(vp.begin(), vp.end());
    for(int i=0; i<vp.size(); i++)
        printf("%d %d %d\n", vp[i].first, vp[i].second.first, vp[i].second.second);

    return 0;
}