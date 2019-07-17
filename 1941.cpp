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
int arr[5][5]; // s = 1, y = 0
bool visit[5][5], v_vis[5][5];
int rs, con_cnt=1;
vector<int> v;

void isConnected(int y, int x) {
    queue<pii> qp;
    qp.push({y, x});
    v_vis[y][x] = 1;
    while (!qp.empty()) {
        x = qp.front().second;
        y = qp.front().first;
        qp.pop();
        fr(i, 0, 4) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if ((0 <= xx && xx < 5) && (0 <= yy && yy < 5)) {
                if(visit[yy][xx] && !v_vis[yy][xx]) {
                    v_vis[yy][xx] = 1;
                    con_cnt++;
                    qp.push({yy, xx});
                }
            }
        }
    }
    if(con_cnt == 7) rs++;
}

void chk() {
    fill(v_vis[0], v_vis[0] + 5 * 5, 0);
    con_cnt = 1;
    fr(i, 0, 5) {
        fr(j, 0, 5) {
            if(visit[i][j]) {
                isConnected(i, j);
                return;
            }
        }
    }
}

void dfs(int num, int s_num, int cnt) {
    if(arr[num/5][num%5] == 1) s_num++;
    visit[num/5][num%5] = 1;
    if(cnt == 7) {
        if(s_num >= 4) { // 인접하면 카운트를 늘린다
            chk();
        }
    } else {
        fr(i, num+1, 25) {
            int x = i / 5, y = i % 5;
            if (!visit[x][y])
                dfs(i, s_num, cnt + 1);
        }
    }
    visit[num/5][num%5] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    fr(i, 0, 5) {
        string s; cin >> s;
        fr(j, 0, 5) {
            if(s[j] == 'S') arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }
    fr(i, 0, 25) {
        fill(visit[0], visit[0]+5*5, 0);
        dfs(i, 0, 1);
    }
    pt(rs);

    return 0;
}