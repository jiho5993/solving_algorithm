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

int dp[1001][1001];

int solution(vector<vector<int>> board) {
    int answer = 0;

    memset(dp, 0, sizeof(dp));
    int y=board.size(), x=board[0].size();
    for(int i=1; i<=y; i++)
        for(int j=1; j<=x; j++)
            dp[i][j] = board[i-1][j-1];
    
    for(int i=1; i<=y; i++) {
        for(int j=1; j<=x; j++) {
            if(dp[i][j]) {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
                answer = max(answer, dp[i][j]);
            }
        }
    }

    return answer*answer;
}

int main() {
    FASTIO;

    auto res = solution({{0, 1, 1, 1},
                         {1, 1, 1, 1},
                         {1, 1, 1, 1},
                         {0, 0, 1, 0}});
    cout << res << '\n';
    cout << solution({{0, 0, 1, 1},
                      {1, 1, 1, 1}});

    return 0;
}