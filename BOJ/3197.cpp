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

#define MX 1501

int r, c;
char pool[MX][MX];
int visit[MX][MX];
int water[MX][MX];
int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue<pair<int, int> > qp;
vector<pair<int, int> > vp;

void init() {
    while(!qp.empty()) qp.pop();
    fr(i, 0, MX) fill(visit[i], visit[i]+MX, 0);
}

bool pos_chk(int xx, int yy) {
    if((0 <= xx && xx < c) && (0 <= yy && yy < r)) return true;
    else return false;
}

int melt() {
    int cnt=1;
    queue<pair<int, int> > mqp;
    fr(i, 0, r) {
        fr(j, 0, c) {
            if(pool[i][j] == '.' || pool[i][j] == 'L') {
                visit[i][j] = 1;
                mqp.push(mp(i, j));
            }
        }
    }
    while(!mqp.empty()) {
        int ss = sz(mqp);
        fr(j, 0, ss) {
            int x = mqp.front().second;
            int y = mqp.front().first;
            mqp.pop();
            visit[y][x] = 1;
            fr(i, 0, 4) {
                int xx = x + go[i][1];
                int yy = y + go[i][0];
                if (pos_chk(xx, yy) && !visit[yy][xx] && pool[yy][xx] != 'L') {
                    water[yy][xx] = cnt;
                    mqp.push(mp(yy, xx));
                    visit[yy][xx] = 1;
                }
            }
        }
        cnt++;
    }
    return cnt-2;
}

bool bfs(int val) {
    int nx = vp[0].second;
    int ny = vp[0].first;
    qp.push(mp(ny, nx));
    visit[ny][nx] = 1;
    while(!qp.empty()) {
        int x = qp.front().second;
        int y = qp.front().first;
        qp.pop();
        fr(i, 0, 4) {
            int xx = x + go[i][1];
            int yy = y + go[i][0];
            if(pos_chk(xx, yy) && !visit[yy][xx] && water[yy][xx] <= val) {
                if (xx == vp[1].second && yy == vp[1].first)
                    return true;
                visit[yy][xx] = 1;
                qp.push(mp(yy, xx));
            }
        }
    }
    return false;
}

int bsearch(int start, int end) {
    init();
    int mid = (start+end+1) / 2;
    if(start > end) return mid;
    bool c = bfs(mid);
    
    if(c) return bsearch(start, mid-1);
    else return bsearch(mid+1, end);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int rs=0, n=0;
    cin >> r >> c;
    fr(i, 0, r) {
        string s; cin >> s;
        fr(j, 0, c) {
            pool[i][j] = s[j];
            if(s[j] == 'L')
                vp.pb(mp(i, j));
        }
    }
    pt(bsearch(0, melt()));

    return 0;
}