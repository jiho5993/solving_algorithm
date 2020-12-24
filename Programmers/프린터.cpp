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

int solution(vector<int> priorities, int location) {
    int answer = 1;

    DQ(P(int)) dq;
    PQ(int) pq;
    for(int i=0; i<priorities.size(); i++) {
        dq.push_back({priorities[i], i});
        pq.push(priorities[i]);
    }

    while(1) {
        P(int) p = dq.front();
        dq.pop_front();
        if(p.first == pq.top()) {
            if(p.second == location) break;
            pq.pop();
            answer++;
            continue;
        }
        dq.push_back(p);
    }

    return answer;
}

int main() {
    FASTIO;

    auto res = solution({1, 1, 9, 1, 1, 1}, 0);
    cout << res;

    return 0;
}