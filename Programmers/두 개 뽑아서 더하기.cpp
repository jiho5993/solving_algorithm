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

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i=0; i<numbers.size()-1; i++)
        for(int j=i+1; j<numbers.size(); j++)
            answer.push_back(numbers[i]+numbers[j]);
    sort(all(answer));
    answer.erase(unique(all(answer)), answer.end());
    return answer;
}

int main() {
    FASTIO;

    V(int) res = solution({5,0,2,7});
    for(auto i:res) {
        cout << i << ' ';
    }

    return 0;
}