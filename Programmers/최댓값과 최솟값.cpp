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

string solution(string s) {
    string answer = "";

    ll mx=-2e9, mn=2e9;
    string cur="";
    for(int i=0; i<s.size(); i++) {
        if(s[i] == ' ') {
            ll tmp = stoll(cur);
            mx = max(tmp, mx);
            mn = min(mn, tmp);
            cur = "";
            continue;
        }
        cur += s[i];
    }
    ll tmp = stoll(cur);
    mx = max(tmp, mx);
    mn = min(mn, tmp);
    answer = to_string(mn) + " " + to_string(mx);

    return answer;
}

int main() {
    FASTIO;

    auto res = solution("1 2 3 4");
    cout << res << '\n';

    return 0;
}