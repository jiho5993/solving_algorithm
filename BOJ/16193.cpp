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

int N;
int arr[1000001];

ll foo1() {
    ll res=0;
    int i=0, j=N-1;
    bool flag = false;
    while(i < j) {
        res += abs(arr[i]-arr[j]);
        !flag ? i++ : j--;
        flag = !flag;
    }
    if(flag) {
        res -= abs(arr[i-1]-arr[j]);
        res += abs(arr[0]-arr[j]);
    } else {
        res -= abs(arr[i]-arr[j+1]);
        res += abs(arr[i]-arr[0]);
    }
    return res;
}

ll foo2() {
    ll res=0;
    int i=0, j=N-1;
    bool flag = false;
    while(i < j) {
        res += abs(arr[i]-arr[j]);
        !flag ? j-- : i++;
        flag = !flag;
    }
    if(flag) {
        res -= abs(arr[i]-arr[j+1]);
        res += abs(arr[i]-arr[N-1]);
    } else {
        res -= abs(arr[i-1]-arr[j]);
        res += abs(arr[N-1]-arr[j]);
    }
    return res;
}

int main() {
    FASTIO;

    sc(N);
    for(int i=0; i<N; i++) sc(arr[i]);
    sort(arr, arr+N);
    cout << max(foo1(), foo2());

    return 0;
}