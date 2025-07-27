#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

struct node {
    int x;
    int y;

    bool operator!=(node o) {
        return x != o.x || y != o.y;
    }
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M, K;
int arr[501][501];
long long cnt[501][501];
int p[4][2];
node visited[501][501];

long long bfs(node st) {
    queue<node> qn;
    qn.push(st);
    visited[st.x][st.y] = st;

    int res = 0;
    while (!qn.empty()) {
        int x = qn.front().x, y = qn.front().y;
        qn.pop();

        if ((p[2][0] <= x && x <= p[3][0]) && (p[2][1] <= y && y <= p[3][1])) {
            res++;
        }

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 > x || x >= N || 0 > y || y >= M) continue;
            if (visited[nx][ny] != node{0, 0}) continue;
            if (arr[nx][ny] == -1) continue;
            visited[nx][ny] = st;
            qn.push({nx, ny});
        }
    }

    cnt[st.x][st.y] = res;

    return res;
}

void solve() {
    cin >> N >> M >> K;
    for (int i=0; i<K; i++) {
        int a, b; cin >> a >> b;
        arr[a-1][b-1] = -1;
    }

    for (int i=0; i<4; i++) {
        cin >> p[i][0] >> p[i][1];
        p[i][0]--, p[i][1]--;
    }

    long long res = 0;
    for (int i=p[0][0]; i<=p[1][0]; i++) {
        for (int j=p[0][1]; j<=p[1][1]; j++) {
            if (arr[i][j] == -1) continue;
            if (visited[i][j] != node{0, 0}) {
                int dup_x = visited[i][j].x;
                int dup_y = visited[i][j].y;
                res += cnt[dup_x][dup_y];
            } else {
                res += bfs({i, j});
            }
        }
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
