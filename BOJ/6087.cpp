#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int W, H;
string arr[101];
int visit[101][101];
vii pos;

void foo() {
    pii st = pos[0];
    visit[st.first][st.second] = 0;
    queue<pair<pii, pii> > qp;
    for(int i=0; i<4; i++) qp.push(mp(st, mp(0, i)));
    while(!qp.empty()) {
        int y = qp.front().first.first;
        int x = qp.front().first.second;
        int cnt = qp.front().second.first;
        int d = qp.front().second.second;
        qp.pop();
        for(int i=0; i<4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            int ncnt = cnt;
            if(xx < 0 || xx >= W || yy < 0 || yy >= H) continue;
            if(arr[yy][xx] == '*') continue;
            if(d != i) ncnt++;
            if(visit[yy][xx] >= ncnt) {
                visit[yy][xx] = ncnt;
                qp.push(mp(mp(yy, xx), mp(ncnt, i)));
            }
        }
    }
    cout << visit[pos[1].first][pos[1].second] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> W >> H;
    for(int i=0; i<H; i++) {
        cin >> arr[i];
        for(int j=0; j<W; j++) {
            if(arr[i][j] == 'C') pos.pb(mp(i, j));
            visit[i][j] = 987654321;
        }
    }
    foo();

    return 0;
}