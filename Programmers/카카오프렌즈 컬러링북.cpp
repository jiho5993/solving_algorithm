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

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
bool is_visited[101][101];

int foo(int cur, int y, int x, int M, int N, V(V(int)) picture) {
    queue<P(int)> qp;
    qp.push({y, x});
    is_visited[y][x] = true;
    int res=1;
    while(!qp.empty()) {
        int y = qp.front().first;
        int x = qp.front().second;
        qp.pop();
        for(int i=0; i<4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if((0 <= yy && yy < M) && (0 <= xx && xx < N)) {
                if(picture[yy][xx] == cur && !is_visited[yy][xx]) {
                    is_visited[yy][xx] = true;
                    qp.push({yy, xx});
                    res++;
                }
            }
        }
    }
    return res;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    memset(is_visited, 0, sizeof(is_visited));
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(!is_visited[i][j] && picture[i][j] != 0) {
                int res = foo(picture[i][j], i, j, m, n, picture);
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, res);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main() {
    FASTIO;

    auto res = solution(6, 4, {{1, 1, 1, 0},
                               {1, 2, 2, 0},
                               {1, 0, 0, 1},
                               {0, 0, 0, 1},
                               {0, 0, 0, 3},
                               {0, 0, 0, 3}});
    cout << res[0] << ' ' << res[1];

    return 0;
}