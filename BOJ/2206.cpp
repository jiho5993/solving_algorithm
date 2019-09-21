#include <bits/stdc++.h>
#define fr(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define len(a) ((int)(a.length()))
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '
using namespace std;

#define MX 1001

struct wall_break {
    int x, y, break_cnt, arrive_cnt;
    wall_break(int yy, int xx, int bc, int ac) {
        x = xx;
        y = yy;
        break_cnt = bc;
        arrive_cnt = ac;
    }
};

int n, m;
int wall[MX][MX], visit[MX][MX][2];
int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs() {
    queue<wall_break> q;
    q.push(wall_break(0, 0, 0, 1));
    visit[0][0][0] = 1;
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int bc = q.front().break_cnt;
        int ac = q.front().arrive_cnt;
        q.pop();
        if(x == m-1 && y == n-1) return ac;
        fr(i, 0, 4) {
            int xx = x + go[i][1];
            int yy = y + go[i][0];
            if((0 <= xx && xx < m) && (0 <= yy && yy < n)) {
                if(wall[yy][xx] == 1 && bc == 0) {
                    visit[yy][xx][bc+1] = 1;
                    q.push(wall_break(yy, xx, bc+1, ac+1));
                } else if(wall[yy][xx] == 0 && !visit[yy][xx][bc]) {
                    visit[yy][xx][bc] = 1;
                    q.push(wall_break(yy, xx, bc, ac+1));
                }
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    fr(i, 0, n) {
        string s; cin >> s;
        fr(j, 0, m)
            wall[i][j] = s[j]-'0';
    }
    int cnt = bfs();
    cnt ? pt(cnt) : pt("-1");

    return 0;
}