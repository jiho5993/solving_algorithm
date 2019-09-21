#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 2147483648;
const int MOD = 1000000007;

struct posd {
    int x, y, dir;
    posd(int yy, int xx, int d) {
        x = xx;
        y = yy;
        dir = d;
    }
};

int n, m;
int area[51][51];
int r, c, d; // 북 0, 동 1, 남 2, 서 3
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int rs;

int nextDir(int d) {
    if(d == 0) return 3;
    else if(d == 1) return 0;
    else if(d == 2) return 1;
    else return 2;
}

void clean() {
    queue<posd> qp;
    qp.push(posd(r, c, d));
    while(!qp.empty()) {
        int x = qp.front().x;
        int y = qp.front().y;
        int dir = qp.front().dir;
        qp.pop();
        if(!area[y][x]) {
            area[y][x] = 2;
            rs++;
        }
        bool flag = false;
        int nd = dir;
        fr(i, 0, 4) {
            nd = nextDir(nd);
            int xx = x + dx[nd];
            int yy = y + dy[nd];
            if((0 <= xx && xx < m) && (0 <= yy && yy < n)) {
                if(!area[yy][xx]) {
                    qp.push(posd(yy, xx, nd));
                    flag  = true;
                    break;
                }
            }
        }
        if(!flag) { // 뒤로 간다
            int xx = x - dx[dir];
            int yy = y - dy[dir];
            if((0 <= xx && xx < m) && (0 <= yy && yy < n)) {
                if(area[yy][xx] != 1) // 벽만 아니면 됨
                    qp.push(posd(yy, xx, dir));
            } else break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> m;
    cin >> r >> c >> d;
    fr(i, 0, n) {
        fr(j, 0, m)
            cin >> area[i][j];
    }
    clean();
    pt(rs);

    return 0;
}