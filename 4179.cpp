#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int r, c;
queue<pair<int, int> > fire;
char miro[1001][1001];
int st_x, st_y, f_arr[1001][1001];
int rs[1001][1001];

void fire_bfs() {
    while(!fire.empty()) {
        int x = fire.front().second;
        int y = fire.front().first;
        fire.pop();
        fr(i, 0, 4) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if((0 <= xx && xx < c) && (0 <= yy && yy < r)) {
                if(!f_arr[yy][xx] && (miro[yy][xx] == 'J' || miro[yy][xx] == '.')) {
                    fire.push({yy, xx});
                    f_arr[yy][xx] = f_arr[y][x] + 1;
                }
            }
        }
    }
}

void jihoon_bfs() {
    queue<pair<int, int> > qp;
    qp.push({st_y, st_x});
    while(!qp.empty()) {
        int x = qp.front().second;
        int y = qp.front().first;
        qp.pop();
        fr(i, 0, 4) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx < 0 || xx >= c || yy < 0 || yy >= r) {
                cout << rs[y][x]+1;
                return;
            }
            if(!rs[yy][xx] && miro[yy][xx] == '.') {
                if(!f_arr[yy][xx]) {
                    rs[yy][xx] = rs[y][x]+1;
                    qp.push({yy, xx});
                }
                if(f_arr[yy][xx] > rs[y][x]+1) {
                    rs[yy][xx] = rs[y][x]+1;
                    qp.push({yy, xx});
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> r >> c;
    fr(i, 0, r) {
        string s; cin >> s;
        fr(j, 0, c) {
            miro[i][j] = s[j];
            if(s[j] == 'J') st_x = j, st_y = i;
            else if(s[j] == 'F') fire.push({i, j});
        }
    }
    fire_bfs();
    jihoon_bfs();

    return 0;
}