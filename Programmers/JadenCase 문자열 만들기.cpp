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
    int i=1;
    s[0] = toupper(s[0]);

    while(s[i] != '\0') {
        if(s[i] == ' ') s[i+1] = toupper(s[i+1]);
        else if('A' <= s[i] && s[i] <= 'Z' && s[i-1] != ' ')
            s[i] = tolower(s[i]);
        i++;
    }

    return s;
}

int main() {
    FASTIO;

    auto res = solution("3people unFollowed me");
    cout << res << '\n';

    return 0;
}