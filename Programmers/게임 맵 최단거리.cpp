#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
bool visited[101][101];

int bfs(vector<vector<int> > maps, int N, int M) {
    queue<tuple<int, int, int> > qt;
    qt.push({0, 0, 1});
    visited[0][0] = true;

    int res = 1e9;
    while (!qt.empty()) {
        int x, y, d;
        tie(x, y, d) = qt.front();
        qt.pop();

        if (x == N-1 && y == M-1) {
            res = min(res, d);
            continue;
        }

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (!maps[nx][ny] || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            qt.push({nx, ny, d+1});
        }
    }

    return res == 1e9 ? -1 : res;
}

int solution(vector<vector<int> > maps) {
    int answer = 0;

    return bfs(maps, maps.size(), maps[0].size());
}
