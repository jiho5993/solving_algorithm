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

int main() {
    FASTIO;

    int arr[] = {2, 4, 8, 16, 32, 64};
    int A, B, C; sc3(A, B, C);
    int s=0, cnt=0;
    for(int x=-100; x<=100; x++) {
        if(A*x*x + B*x + C == 0) {
            s++;
            for(auto i:arr) {
                if(i == x)
                    cnt++;
            }
        }
    }

    if(s == 2) cnt == 2 ? cout << "이수근" : cout << "정수근";
    else cout << "둘다틀렸근";

    return 0;
}