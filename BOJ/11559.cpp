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

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
char puyo[12][6];
bool visit[12][6];
int rs;
vector<pii> v;

void dfs(int y, int x, char p) {
    v.pb({y, x});
    visit[y][x] = 1;
    fr(i, 0, 4) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if((0 <= xx && xx < 6) && (0 <= yy && yy < 12)) {
            if(!visit[yy][xx] && puyo[yy][xx] == p) {
                dfs(yy, xx, p);
            }
        }
    }
}

void down_puyo() {
    for(int i=11; i>=0; i--) {
        fr(j, 0, 6) {
            int idx = 11;
            if(puyo[i][j] == '.') {
                for(int k=i; k>=0; k--) {
                    if(puyo[k][j] != '.') {
                        fr(l, 0, 11) {
                            if(puyo[idx][j] == '.') break;
                            idx--;
                        }
                        puyo[idx][j] = puyo[k][j];
                        puyo[k][j] = '.';
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    fr(i, 0, 12) {
        string s; cin >> s;
        fr(j, 0, 6)
            puyo[i][j] = s[j];
    }
    while(1) {
        bool chk = false;
        fill(visit[0], visit[0]+12*6, 0);
        fr(i, 0, 12) {
            fr(j, 0, 6) {
                if(!visit[i][j] && puyo[i][j] != '.') {
                    v.clear();
                    dfs(i, j, puyo[i][j]);
                    if(v.size() >= 4) {
                        chk = true;
                        fr(k, 0, v.size())
                            puyo[v[k].first][v[k].second] = '.';
                    }
                }
            }
        }
        if(chk) rs++;
        else break;
        down_puyo();
    }
    pt(rs);

    return 0;
}