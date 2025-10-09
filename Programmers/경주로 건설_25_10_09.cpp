#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr
#define ll long long
#define pii pair<int, int>

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
int dp[30][30][4];
int res = 1e9;

void dfs(int x, int y, int dir, int cost, vector<vector<int> > board) {
    if (res < cost) return;
    if (x == N-1 && y == N-1) {
        res = min(res, cost);
        return;
    }

    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
        if (board[nx][ny]) continue;

        int nc = cost + 100;
        if ((dir == 0 || dir == 1) && (i == 2 || i == 3)) nc += 500;
        if ((dir == 2 || dir == 3) && (i == 0 || i == 1)) nc += 500;

        if (nc >= dp[nx][ny][i]) continue;
        dp[nx][ny][i] = nc;
        dfs(nx, ny, i, nc, board);
    }
}

int solution(vector<vector<int>> board) {
    N = board.size();
    for (int i=0; i<30; i++) {
        for (int j=0; j<30; j++) {
            for (int k=0; k<4; k++) {
                dp[i][j][k] = 1e9;
            }
        }
    }

    dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = dp[0][0][3] = 0;
    dfs(0, 0, -1, 0, board);
    return res;
}
