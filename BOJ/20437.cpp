#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0)
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define ll long long
#define sc(x) cin>>x;
#define sc2(x,y) cin>>x>>y
#define sc3(x,y,z) cin>>x>>y>>z
#define sc4(x,y,z,w) cin>>x>>y>>z>>w
#define P(T) pair<T,T>
#define V(T) vector<T>
#define Q(T) queue<T>
#define S(T) stack<T>
#define DQ(T) deque<T>
#define VP(T) vector<pair<T,T>>
#define QP(T) queue<pair<T,T>>
#define SP(T) stack<pair<T,T>>
#define PQ(T) priority_queue<T>
#define GPQ(T) priority_queue<T,vector<T>,greater<T>>

int main() {
    FASTIO;

    int T, K; sc(T);
    string W;
    while(T--) {
        sc2(W, K);
        int mn=2e9, mx=-1;
        V(V(int)) v = V(V(int))(26);
        for(int i=0; i<W.size(); i++) {
            int cur = W[i]-'a';
            v[cur].pb(i);
            if(v[cur].size() >= K) {
                mn = min(mn, i-v[cur][v[cur].size()-K]+1);
                mx = max(mx, i-v[cur][v[cur].size()-K]+1);
            }
        }
        if(mx == -1) cout << -1 << '\n';
        else cout << mn << ' ' << mx << '\n';
    }

    return 0;
}