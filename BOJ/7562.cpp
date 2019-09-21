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

int t, l;
int ch[301][301], visit[301][301];
int go[8][2] = {{-2, 1}, {-1, 2}, {2, 1}, {1, 2}, {-2, -1}, {-1, -2}, {2, -1}, {1, -2}};

void init() {
    fr(i, 0, 301) {
        fill(ch[i], ch[i]+301, 0);
        fill(visit[i], visit[i]+301, 0);
    }
}

void bfs(int s1, int s2, int d1, int d2) {
    queue<pair<int, int> > qp;
    qp.push(mp(s1, s2));
    visit[s1][s2] = 1;
    while(!qp.empty()) {
        int ss = sz(qp);
        fr(i, 0, ss) {
            int x = qp.front().first;
            int y = qp.front().second;
            qp.pop();
            if(mp(x, y) == mp(d1, d2)) return;
            fr(j, 0, 8) {
                int xx = x + go[j][1];
                int yy = y + go[j][0];
                if((0 <= xx && xx < l) && (0 <= yy && yy < l) && !visit[xx][yy]) {
                    qp.push(mp(xx, yy));
                    visit[xx][yy] = 1;
                    ch[xx][yy] = ch[x][y] + 1;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> t;
    while(t--) {
        int s1, s2, d1, d2;
        init();
        cin >> l >> s1 >> s2 >> d1 >> d2;
        bfs(s1, s2, d1, d2);
        pt(ch[d1][d2]);
    }

    return 0;
}