#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define len(a) ((int)(a.length()))
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 2147483648;
const int MOD = 1000000007;

struct pos { int x, y; };

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int n, m, cnt;
int visit[101][101], box[101][101], new_visit[101][101];
queue<pos> q_pos;
vector<pos> v_pos[101][101];

int bfs() {
    bool flag = false;
    while(!q_pos.empty()) {
        int x = q_pos.front().x;
        int y = q_pos.front().y;
        q_pos.pop();
        if(!new_visit[x][y] && !v_pos[x][y].empty()) { // 새로운 곳을 방문한다면,
            fr(i, 0, sz(v_pos[x][y])) {
                int nx = v_pos[x][y][i].x;
                int ny = v_pos[x][y][i].y;
                box[nx][ny] = 1;
            }
            new_visit[x][y] = 1;
            flag = true;
        }
        fr(i, 0, 4) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if((0 < xx && xx <= n) && (0 < yy && yy <= n)) {
                if(box[xx][yy] && !visit[xx][yy]) {
                    visit[xx][yy] = 1;
                    q_pos.push({xx, yy});
                }
            }
        }
    }
    return flag;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int x, y, a, b;
    cin >> n >> m;
    fr(i, 0, m) {
        cin >> x >> y >> a >> b;
        v_pos[x][y].pb({a, b});
    }
    bfs();
    while(1) {
        fill(visit[0], visit[0]+101*101, 0);
        visit[1][1] = 1;
        box[1][1] = 1;
        q_pos.push({1, 1});
        if(!bfs()) break;
    }
    fr(i, 1, n+1) {
        fr(j, 1, n+1) {
            if(box[i][j])
                cnt++;
        }
    }
    pt(cnt);

    return 0;
}