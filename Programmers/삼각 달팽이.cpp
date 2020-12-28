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

vector<int> solution(int n) {
    vector<int> answer;

    int sz=(n*(n+1))/2;
    V(V(int)) arr(n+1, V(int)(n+1));

    int i=0, j=0;
    int nxt=n, cnt=1, type=0; // 0: down, 1: right, 2: up
    while(cnt <= sz) {
        if(type == 0) {
            for(int k=0; k<nxt; k++) arr[i++][j] = cnt++;
            i--, j++;
            type = 1;
        } else if(type == 1) {
            for(int k=0; k<nxt; k++) arr[i][j++] = cnt++;
            i--, j-=2;
            type = 2;
        } else {
            for(int k=0; k<nxt; k++) arr[i--][j--] = cnt++;
            i+=2, j++;
            type = 0;
        }
        nxt--;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j])
                answer.pb(arr[i][j]);
        }
    }

    return answer;
}

int main() {
    FASTIO;

    auto res = solution(6);
    cout << '[';
    for(auto i:res) cout << i << ',';
    cout << ']';

    return 0;
}