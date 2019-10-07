#include <bits/stdc++.h>
using namespace std;

struct info {
    int y, x, l, r;
};

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int N, M, L, R, ret;
int arr[1001][1001];
bool visit[1001][1001];
queue<info> q;

void foo(int yy, int xx, int l, int r) {
    if(!arr[yy][xx] && !visit[yy][xx] && (0 <= yy && yy < N) && (0 <= xx && xx < M)) {
        visit[yy][xx] = 1;
        q.push({yy, xx, l, r});
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> N >> M >> L >> R;
    for(int i=0; i<N; i++) {
        string s; cin >> s;
        for(int j=0; j<M; j++) {
            arr[i][j] = s[j]-'0';
            if(s[j] == '2') {
                q.push({i, j, L, R});
                visit[i][j] = 1;
            }
        }
    }
    while(!q.empty()) {
        info tmp = q.front();
        q.pop();
        int x = tmp.x, y = tmp.y;
        int l = tmp.l, r = tmp.r;
        while (y++ < N && !arr[y][x] && !visit[y][x]) {
            visit[y][x] = 1;
            q.push({y, x, l, r});
        }
        y = tmp.y;
        while (y-- >= 0 && !arr[y][x] && !visit[y][x]) {
            visit[y][x] = 1;
            q.push({y, x, l, r});
        }
        y = tmp.y;
        if (l > 0) foo(y, x-1, l-1, r);
        if (r > 0) foo(y, x+1, l, r-1);
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(visit[i][j])
                ret++;
        }
    }
    cout << ret;

    return 0;
}