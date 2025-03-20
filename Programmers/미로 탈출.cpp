#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

#define qti queue<tuple<int, int, int> >

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int N, M;
int sx, sy, ex, ey, lx, ly;
bool visited[101][101];
int res1 = 1e9, res2 = 1e9;

bool verify(vector<string> arr, int nx, int ny) {
    if (nx < 0 || nx >= N || ny < 0 || ny >= M) return false;
    if (arr[nx][ny] == 'X' || visited[nx][ny]) return false;
    return true;
}

void find_l(vector<string> arr, int N, int M) {
    qti qt;
    qt.push({sx, sy, 0});
    visited[sx][sy] = true;

    while (!qt.empty()) {
        int x, y, d;
        tie(x, y, d) = qt.front();
        qt.pop();
        
        if (x == lx && y == ly) {
            res1 = min(res1, d);
            continue;
        }

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!verify(arr, nx, ny)) continue;
            visited[nx][ny] = true;
            qt.push({nx, ny, d+1});
        }
    }
}

void find_e(vector<string> arr, int N, int M) {
    qti qt;
    qt.push({lx, ly, 0});
    visited[lx][ly] = true;

    while (!qt.empty()) {
        int x, y, d;
        tie(x, y, d) = qt.front();
        qt.pop();
        
        if (x == ex && y == ey) {
            res2 = min(res2, d);
            continue;
        }

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!verify(arr, nx, ny)) continue;
            visited[nx][ny] = true;
            qt.push({nx, ny, d+1});
        }
    }
}

int solution(vector<string> maps) {
    N = maps.size(), M = maps[0].size();
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (maps[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (maps[i][j] == 'E') {
                ex = i;
                ey = j;
            } else if (maps[i][j] == 'L') {
                lx = i;
                ly = j;
            }
        }
    }

    find_l(maps, N, M);
    memset(visited, 0, sizeof(bool)*101*101);
    find_e(maps, N, M);

    if (res1 == 1e9 || res2 == 1e9) return -1;
    return res1 + res2;
}
