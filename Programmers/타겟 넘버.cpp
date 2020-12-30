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

int foo(V(int) numbers, int idx, int s, int target) {
    int ret = 0;
    if(idx == numbers.size()) {
        if(s == target) return 1;
        else return 0;
    }
    ret += foo(numbers, idx+1, s+numbers[idx], target);
    ret += foo(numbers, idx+1, s-numbers[idx], target);
    return ret;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    answer = foo(numbers, 0, 0, target);

    return answer;
}

int main() {
    FASTIO;

    auto res = solution({1, 1, 1, 1, 1}, 3);
    cout << res;

    return 0;
}