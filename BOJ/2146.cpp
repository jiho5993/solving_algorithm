#include <bits/stdc++.h>
#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define len(a) ((int)(a.length()))
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '
using namespace std;

int n, minNum = 9999999, num=1;
int MAP[101][101], visit[101][101];
int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y, int num) {
    visit[x][y] = 1;
    MAP[x][y] = num;
    fr(i, 0, 4) {
        int xx = x + go[i][1];
        int yy = y + go[i][0];
        if((0 <= xx && xx < n) && (0 <= yy && yy < n) && !visit[xx][yy] && MAP[xx][yy])
            dfs(xx, yy, num);
    }
}

int bfs(int num) {
    queue<pair<int, int> > qp;
    fr(i, 0, n) {
        fr(j, 0, n) {
            if(MAP[i][j] == num) {
                visit[i][j] = 1;
                qp.push(mp(i, j));
            }
        }
    }
    int rs=0;
    while(!qp.empty()) {
        int ss = sz(qp);
        fr(i, 0, ss) {
            int x = qp.front().first;
            int y = qp.front().second;
            qp.pop();
            fr(j, 0, 4) {
                int xx = x + go[j][1];
                int yy = y + go[j][0];
                if ((0 <= xx && xx < n) && (0 <= yy && yy < n)) {
                    if (MAP[xx][yy] != num && MAP[xx][yy] > 0)
                        return rs;
                    else if (!MAP[xx][yy] && !visit[xx][yy]) {
                        qp.push(mp(xx, yy));
                        visit[xx][yy] = 1;
                    }
                }
            }    
        }
        rs++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n;
    fr(i, 0, n) {
        fr(j, 0, n)
            cin >> MAP[i][j];
    }
    fr(i, 0, n) { // 섬에 이름 붙여주기
        fr(j, 0, n) {
            if(MAP[i][j] && !visit[i][j])
                dfs(i, j, num++);
        }
    }
    fr(i, 1, num) {
        fr(j, 0, 101) fill(visit[j], visit[j]+101, 0);
        minNum = min(minNum, bfs(i));
    }
    pt(minNum);

    return 0;
}