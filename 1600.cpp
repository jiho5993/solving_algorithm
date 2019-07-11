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

struct dt {
    int x, y, result, ab;
    dt(int yy, int xx, int rs, int aa) {
        x = xx;
        y = yy;
        result = rs;
        ab = aa;
    }
};

int k, w, h;
int tr[201][201], visit[201][201][31];
int ability[8][2] = {{2, -1}, {2, 1}, {-2, -1}, {-2, 1}, {1, 2}, {1, -2}, {-1, -2}, {-1, 2}};
int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs() {
    queue<dt> qp;
    qp.push(dt(0, 0, 1, 0));
    visit[0][0][0] = 1;
    while(!qp.empty()) {
        int x = qp.front().x;
        int y = qp.front().y;
        int rs = qp.front().result;
        int aa = qp.front().ab;
        qp.pop();
        if(x == w-1 && y == h-1) return rs-1;
        fr(j, 0, 4) {
            int xx = x + go[j][1];
            int yy = y + go[j][0];
            if((0 <= xx && xx < w) && (0 <= yy && yy < h)) {
                if(!visit[yy][xx][aa] && !tr[yy][xx]) {
                    qp.push(dt(yy, xx, rs+1, aa));
                    visit[yy][xx][aa] = 1;
                }
            }
        }
        if(aa < k) {
            fr(j, 0, 8) {
                int xx = x + ability[j][1];
                int yy = y + ability[j][0];
                if((0 <= xx && xx < w) && (0 <= yy && yy < h)) {
                    if(!visit[yy][xx][aa+1] && !tr[yy][xx]) {
                        qp.push(dt(yy, xx, rs+1, aa+1));
                        visit[yy][xx][aa+1] = 1;
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> k >> w >> h;
    fr(i, 0, h) {
        fr(j, 0, w)
            cin >> tr[i][j];
    }
    pt(bfs());

    return 0;
}