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

    int T; sc(T);
    while(T--) {
        int arr[7], s=0, mn=101;
        for(int i=0; i<7; i++) {
            sc(arr[i]);
            if(!(arr[i]&1)) {
                mn = min(mn, arr[i]);
                s += arr[i];
            }
        }
        cout << s << ' ' << mn << '\n';
        
    }

    return 0;
}