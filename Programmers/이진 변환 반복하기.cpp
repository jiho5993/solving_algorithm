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

string foo(int n) {
    string ret="";
    while(n) {
        ret += to_string(n%2);
        n/=2;
    }
    reverse(all(ret));
    return ret;
}

vector<int> solution(string s) {
    vector<int> answer;
    int z=0, cnt=0;

    while(1) {
        if(s == "1") break;
        string tmp="";
        for(auto i:s) if(i == '1') tmp += i;
        z += s.size()-tmp.size();
        s = foo(tmp.size());
        cnt++;
    }
    answer = {cnt, z};

    return answer;
}

int main() {
    FASTIO;

    auto res = solution("1111111");
    cout << res[0] << ' ' << res[1] << '\n';

    return 0;
}