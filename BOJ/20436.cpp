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

int res=0;
char a, b;
string f, r="yuiophjklbnm";
map<char, P(int)> m;

void pre() {
    m['q']={0,0}, m['w']={0,1}, m['e']={0,2}, m['r']={0,3}, m['t']={0,4}, m['y']={0,5}, m['u']={0,6}, m['i']={0,7}, m['o']={0,8}, m['p']={0,9};
    m['a']={1,0}, m['s']={1,1}, m['d']={1,2}, m['f']={1,3}, m['g']={1,4}, m['h']={1,5}, m['j']={1,6}, m['k']={1,7}, m['l']={1,8};
    m['z']={2,0}, m['x']={2,1}, m['c']={2,2}, m['v']={2,3}, m['b']={2,4}, m['n']={2,5}, m['m']={2,6};
}

int main() {
    FASTIO;

    pre();
    sc3(a, b, f);
    
    for(auto i:f) {
        if(r.find(i) != string::npos) {
            res += (1+abs(m[b].first-m[i].first)+abs(m[b].second-m[i].second));
            b = i;
        } else {
            res += (1+abs(m[a].first-m[i].first)+abs(m[a].second-m[i].second));
            a = i;
        }
    }
    cout << res;

    return 0;
}