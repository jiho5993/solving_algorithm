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

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
bool arr[201][201];
int visited[201][201];
int i_x, i_y;

bool is_range(int x, int y) {
    return 0 <= x && x <= 200 && 0 <= y && y <= 200;
}

bool is_inside(int x, int y) {
    for (int i=0; i<8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!is_range(nx, ny)) return false;
        if (!arr[nx][ny]) return false;
    }
    return true;
}

int bfs(int x, int y) {
    queue<pair<int, pii> > qp;
    for (int i=0; i<200; i++) fill(visited[i], visited[i]+200, 1e9);

    qp.push({0, {x, y}});
    visited[x][y] = 0;

    while (!qp.empty()) {
        int s = qp.front().first;
        int x = qp.front().second.first;
        int y = qp.front().second.second;
        qp.pop();

        if (x == i_x && y == i_y) {
            continue;
        }

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!is_range(nx, ny)) continue;
            if (visited[nx][ny] < s+1) continue;
            if (!arr[nx][ny]) continue;
            if (is_inside(nx, ny)) continue;
            visited[nx][ny] = s+1;
            qp.push({s+1, {nx, ny}});
        }
    }

    return visited[i_x][i_y];
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    for (auto cur: rectangle) {
        for (int i=cur[0]*2; i<=cur[2]*2; i++) {
            for (int j=cur[1]*2; j<=cur[3]*2; j++) {
                arr[i][j] = true;
            }
        }
    }

    i_x = itemX*2;
    i_y = itemY*2;

    return bfs(characterX*2, characterY*2) / 2;
}
