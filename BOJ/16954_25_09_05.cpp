#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int arr[10][10];
bool visited[10][10][10];

bool bfs() {
    queue<tuple<int, int, int> > qt;
    qt.push({7, 0, 0});
    visited[7][0][0] = true;

    while (!qt.empty()) {
        int x, y, t;
        tie(x, y, t) = qt.front();
        qt.pop();

        if (x == 0 && y == 7) return true;

        for (int i=0; i<9; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nt = min(t+1, 8);

            if (0 > nx || nx >= 8 || 0 > ny || ny >= 8) continue;
            
            if (nx-t >= 0 && arr[nx-t][ny] == -1) continue; // 현재
            if (nx-nt >= 0 && arr[nx-nt][ny] == -1) continue; // 한칸 내려갔을 때

            if (visited[nx][ny][nt]) continue;

            visited[nx][ny][nt] = true;
            qt.push({nx, ny, nt});
        }
    }

    return false;
}

void solve() {
    for (int i=0; i<8; i++) {
        string s; cin >> s;
        for (int j=0; j<8; j++) {
            if (s[j] == '.') arr[i][j] = 0;
            else if (s[j] == '#') arr[i][j] = -1;
        }
    }

    cout << bfs();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
