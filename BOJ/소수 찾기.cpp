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

const int MAX = 10000001;
int answer = 0;
bool p[MAX], isused[MAX], selected[9];

void eratos() {
    p[0] = p[1] = true;
    for(int i=2; i*i<=MAX; i++) {
        if(p[i]) continue;
        for(int j=i*2; j<=MAX; j+=i) p[j] = true;
    }
}

void foo(string res, string s) {
    if(res != "" && !p[stoi(res)] && !isused[stoi(res)]) {
        answer++;
        isused[stoi(res)] = true;
    }

    for(int i=0; i<s.size(); i++) {
        if(selected[i]) continue;
        selected[i] = true;
        foo(res+s[i], s);
        selected[i] = false;
    }
}

int solution(string numbers) {

    eratos();
    foo("", numbers);

    return answer;
}

int main() {
    FASTIO;

    auto res = solution("17");
    cout << res;
    
    return 0;
}