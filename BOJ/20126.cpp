#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N, M, S; cin >> N >> M >> S;
    vector<pair<int, int> > v;
    for(int i=0; i<N; i++) {
        int a, b; cin >> a >> b;
        v.pb(mp(a, b));
    }
    sort(all(v));
    int cur_time = 0, res = -1;
    for(auto i:v) {
        int s=i.first, t=i.second;
        int diff = s - cur_time;
        if(diff >= M) {
            res = cur_time;
            break;
        }
        cur_time = s + t;
    }
    if(S-cur_time >= M) res = cur_time;
    cout << res;

    return 0;
}