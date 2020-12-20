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
#define Q(T) queue<T,T>
#define S(T) stack<T>
#define DQ(T) deque<T>
#define VP(T) vector<pair<T,T>>
#define QP(T) queue<pair<T,T>>
#define SP(T) stack<pair<T,T>>
#define PQ(T) priority_queue<T>
#define GPQ(T) priority_queue<T,vector<T>,greater<T>>

int N;
int arr[21];
map<int, bool> m;

void foo(int idx, int sum) {
    if(idx == N) {
        m[sum] = true;
        return;
    }
    foo(idx+1, sum+arr[idx]);
    foo(idx+1, sum);
}

int main() {
    FASTIO;

    sc(N);
    for(int i=0; i<N; i++) sc(arr[i]);
    foo(0, 0);
    for(int i=1; ; i++) {
        if(!m[i]) {
            cout << i;
            break;
        }
    }

    return 0;
}