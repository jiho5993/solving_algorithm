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

struct man {
    int x, y, cnt;
    man(int yy, int xx, int cc) {
        x = xx;
        y = yy;
        cnt = cc;
    }
};

int t, w, h;
char bd[1001][1001], visit[1001][1001];
int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue<man> qp;

void clear() {
    while(!qp.empty()) qp.pop();
    fr(i, 0, 1001) {
        fill(visit[i], visit[i]+1001, 0);
        fill(bd[i], bd[i]+1001, 0);
    }
}

int bfs(int my, int mx) {
    visit[my][mx] = 1;
    qp.push(man(my, mx, 1));
    while(!qp.empty()) {
        int x = qp.front().x;
        int y = qp.front().y;
        int cnt = qp.front().cnt;
        qp.pop();
        fr(i, 0, 4) {
            int xx = x + go[i][1];
            int yy = y + go[i][0];
            if((0 <= xx && xx < w) && (0 <= yy && yy < h)) {
                if(bd[y][x] == '@') {
                    if(!visit[yy][xx] && bd[yy][xx] == '.') {
                        if(xx == 0 || xx == w-1 || yy == 0 || yy == h-1)
                            return cnt+1;
                        else {
                            bd[yy][xx] = '@';
                            qp.push(man(yy, xx, cnt+1));
                        }
                    }
                } else if(!visit[yy][xx] && bd[yy][xx] != '#') {
                    visit[yy][xx] = 1;
                    qp.push(man(yy, xx, cnt+1));
                }
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int mx, my;
    cin >> t;
    while(t--) {
        clear();
        cin >> w >> h;
        fr(i, 0, h) {
            string s; cin >> s;
            fr(j, 0, w) {
                bd[i][j] = s[j];
                if(bd[i][j] == '@') {
                    my = i;
                    mx = j;
                } else if(bd[i][j] == '*')
                    qp.push(man(i, j, 0));
            }
        }
        int rs = bfs(my, mx);
        if(mx == 0 || mx == w-1 || my == 0 || my == h-1) rs = 1;
        rs ? pt(rs) : pt("IMPOSSIBLE");
    }

    return 0;
}